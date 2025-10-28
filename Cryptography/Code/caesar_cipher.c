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
  
