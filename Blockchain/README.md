# Blockchain — Theory, Mathematics, Programming & Security

This code implements a simple **Blockchain** in the **C programming language**.
It demonstrates the fundamental principles behind blockchain technology — including how blocks are linked, verified, and protected through cryptographic hashing.
The project covers the blockchain’s **theoretical foundation**, **mathematical model**, **programming implementation**, and **security perspective**.

## 1. Theoretical Overview

A **blockchain** is a continuously growing list of records called **blocks**, which are **linked and secured** using **cryptography**.
Each block contains essential data and a unique hash that ties it to the previous block, forming an immutable chain.

### Concept

Each block consists of:

* **Index** — Position of the block in the chain
* **Timestamp** — When the block was created
* **Data** — Transaction or message
* **Previous Hash** — Hash of the previous block
* **Hash** — Unique digital fingerprint of the current block

### Structure

```
Genesis Block
   ↓
Block 1  →  Block 2  →  Block 3  → ...
```

If even a single block’s data changes, its hash changes, breaking the entire chain — providing **tamper detection** and **integrity**.

## 2. Mathematical Foundation

Blockchain relies on **cryptographic hash functions**, which convert data into a fixed-size hash value.
The hash acts like a fingerprint — deterministic, irreversible, and highly sensitive to input changes.

### Hash Formula

For a given block:

```
hash = SHA256(index + previous_hash + timestamp + data)
```

Where:

* **index** → numerical position of the block
* **previous_hash** → hash of the preceding block
* **timestamp** → time of creation (seconds since epoch)
* **data** → any string stored in the block

The **SHA-256** algorithm is a one-way function that outputs a 256-bit (64 hex characters) hash.

### Properties of SHA-256:

| Property                | Description                                   |
| ----------------------- | --------------------------------------------- |
| **Deterministic**       | Same input → same output                      |
| **Irreversible**        | Hash cannot be converted back to input        |
| **Collision-resistant** | Extremely unlikely two inputs have same hash  |
| **Avalanche Effect**    | Tiny input change → completely different hash |

Mathematically, if block *i* depends on *block (i-1)*:

```
hash_i = H(index_i + hash_(i-1) + timestamp_i + data_i)
```

This chaining ensures that **any change propagates forward**, breaking the chain’s validity.

## 3. Programming Implementation

### Language

C (with OpenSSL for SHA-256 hashing)

### Key Features

* Implements blockchain structure with linked blocks
* Each block stores its index, data, timestamp, and hash
* Uses SHA-256 hashing via OpenSSL
* Validates the blockchain’s integrity
* Prevents buffer overflow using `snprintf()`

### Code Structure

#### Data Structure

```
typedef struct Block {
    int index;
    char previous_hash[65];
    char data[256];
    long timestamp;
    char hash[65];
    struct Block *next;
} Block;
```

#### Core Functions

| Function                 | Description                                    |
| ------------------------ | ---------------------------------------------- |
| `calculate_hash()`       | Generates SHA-256 hash for a block             |
| `create_genesis_block()` | Creates the first block (Genesis Block)        |
| `add_block()`            | Adds a new block to the chain                  |
| `is_chain_valid()`       | Verifies that all hashes and links are correct |
| `print_chain()`          | Displays all blocks and their data             |

#### Example Snippet

```
snprintf(input, sizeof(input), "%d%s%ld%s",
         block->index, block->previous_hash,
         block->timestamp, block->data);
SHA256((unsigned char *)input, strlen(input), hash);
```

This combines block data into one string and hashes it securely.

### Sample Output

```
Block 0:
Timestamp: Thu Oct 31 21:25:30 2025
Data: Genesis Block
Hash: 0ab3a2b76de73a9e...
Previous Hash: 0

Block 1:
Data: Drashti sent 2 BTC to Alice
Hash: f5b2c8e84a3d99c7...
Previous Hash: 0ab3a2b76de73a9e...

Blockchain valid? Yes
```

## 4. Security Analysis

Even though this blockchain demonstrates the foundational concept of immutability, it’s **not secure for production**.
It lacks consensus mechanisms, proof-of-work, and peer-to-peer validation.

### Security Features

| Feature             | Description                                          |
| ------------------- | ---------------------------------------------------- |
| **Hash Linking**    | Each block references the hash of the previous block |
| **Data Integrity**  | Any change in data breaks subsequent hashes          |
| **SHA-256 Hashing** | Provides cryptographic-level fingerprinting          |
| **Buffer Safety**   | Uses `snprintf()` to prevent buffer overflow         |

### Weaknesses

| Weakness            | Description                                 |
| ------------------- | ------------------------------------------- |
| **No Consensus**    | Single system — no distributed verification |
| **No Mining / PoW** | No computational cost for altering blocks   |
| **Memory Only**     | Data isn’t stored persistently              |
| **No Encryption**   | Transactions are stored in plaintext        |

### Conclusion

This project is a **conceptual and educational demonstration** of how a blockchain works internally — linking, hashing, and validating data.
It explains **why blockchains are tamper-proof** and how **cryptographic math** maintains trust.
However, it’s **not a secure ledger** — it lacks decentralization, consensus, and encryption.

## 5. Learning Outcomes

From this project, you will:

* Understand the **structure and theory** of a blockchain
* Apply **cryptographic hash functions** (SHA-256)
* Implement **linked data structures** in C
* See **how immutability is mathematically achieved**
* Recognize **security limitations** in basic implementations.

## References

* [GeeksforGeeks — Blockchain Basics](https://www.geeksforgeeks.org/blockchain-technology-introduction/)
* [Wikipedia — Blockchain](https://en.wikipedia.org/wiki/Blockchain)
* Chatgpt to understand code line by line.
