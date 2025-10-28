// A simple encryption-decryption program implementing the Caesar Cipher algorithm in C.

# include <stdio.h>
# include <ctype.h>
# include <string.h>

// Function prototypes
void encrypt (char text[], int key);
void decrypt (char text[], int key);

int main() {
  char text[500];
  int key, choice;

  printf("===Caesar Cipher Implementation===\n");
  printf("1. Encrypt \n2. Decrypt \nChoose an option (1/2):");
  scanf("%d", &choice);
  getchar(); //to consume leftover newline

  printf("Enter your message:");
  fgets(text, sizeof(text), stdin);

  printf("Enter key (1-25):");
  scanf("%d", &key);

  if (choice==1){
    encrypt(text, key);
  }
  else if (choice==2){
    decrypt(text, key);
  }
  else {
    printf("Invalid choice.\n");
  }
  return 0;
}

void encrypt(char text[], int key){
  for (int i=0; text[i] != '\0'; ++i){
    char ch=text[i];

    if (islower(ch)){
      text[i] = (ch - 'a' + key) % 26 + 'a';
    }
    else if (isupper(ch)){
      text[i] = (ch - 'A' + key) % 26 + 'A';
    }
    else if (isdigit(ch)){
      text[i] = (ch - '0' + key) % 10 + '0';
    }
    // else -> leave space/symbols unchanged
  }
  printf("\nEncrypted message: %s\n", text);
}

void decrypt(char text[], int key){
  for (int i=0; text[i] != '\0'; ++i){
    char ch=text[i];

    if (islower(ch)){
      text[i] = (ch - 'a' - key + 26) % 26 + 'a';
    }
    else if (isupper(ch)){
      text[i] = (ch - 'A' - key + 26) % 26 + 'A';
    }
    else if (isdigital(ch)){
      text[i] = (ch - '0' - key + 10) % 10 + '0';
    }
    // else -> leaves unchange
  }
  printf("\nDecrypted message: %s\n", text);
}
