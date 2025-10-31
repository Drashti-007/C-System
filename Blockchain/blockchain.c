#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h> // For SHA256 hashing

// Block structure
typedef struct Block {
    int index;
    char previous_hash[65];
    char data[256];
    long timestamp;
    char hash[65];
    struct Block *next;
} Block;

// Function to compute SHA-256 hash
void calculate_hash(Block *block, char *output_hash) {
    char input[1024];
    snprintf(input, sizeof(input), "%d%s%ld%s", block->index, block->previous_hash, block->timestamp, block->data);

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)input, strlen(input), hash);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(output_hash + (i * 2), "%02x", hash[i]);

    output_hash[64] = '\0';
}

// Create the genesis (first) block
Block* create_genesis_block() {
    Block *block = (Block*)malloc(sizeof(Block));
    block->index = 0;
    strcpy(block->previous_hash, "0");
    strcpy(block->data, "Genesis Block");
    block->timestamp = time(NULL);
    calculate_hash(block, block->hash);
    block->next = NULL;
    return block;
}

// Add a new block
Block* add_block(Block *previous_block, const char *data) {
    Block *new_block = (Block*)malloc(sizeof(Block));
    new_block->index = previous_block->index + 1;
    strcpy(new_block->previous_hash, previous_block->hash);
    strcpy(new_block->data, data);
    new_block->timestamp = time(NULL);
    calculate_hash(new_block, new_block->hash);
    new_block->next = NULL;
    previous_block->next = new_block;
    return new_block;
}

// Validate blockchain
int is_chain_valid(Block *chain) {
    Block *current = chain;
    while (current->next != NULL) {
        Block *next = current->next;
        char recalculated_hash[65];
        calculate_hash(current, recalculated_hash);

        if (strcmp(current->hash, recalculated_hash) != 0) return 0;
        if (strcmp(next->previous_hash, current->hash) != 0) return 0;

        current = current->next;
    }
    return 1;
}

// Print blockchain
void print_chain(Block *chain) {
    Block *current = chain;
    while (current != NULL) {
        printf("\nBlock %d:\n", current->index);
        printf("Timestamp: %s", ctime(&current->timestamp));
        printf("Data: %s\n", current->data);
        printf("Hash: %s\n", current->hash);
        printf("Previous Hash: %s\n", current->previous_hash);
        current = current->next;
    }
}

int main() {
    Block *genesis = create_genesis_block();
    Block *last = genesis;

    last = add_block(last, "Drashti sent 2 BTC to Alice");
    last = add_block(last, "Alice sent 1 BTC to Bob");

    print_chain(genesis);

    printf("\nBlockchain valid? %s\n", is_chain_valid(genesis) ? "Yes" : "No");
    return 0;
}
