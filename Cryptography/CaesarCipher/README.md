
# Caesar Cipher — Theory, Mathematics, Programming & Security

This code implements the **Caesar Cipher**, one of the oldest and simplest encryption algorithms.
It’s a **substitution cipher** where each letter and digit in the message is shifted by a user-defined key.
This demonstrates the cipher’s **theory, mathematics, implementation**, and its **security weaknesses**.

## 1. Theoretical Overview

The **Caesar Cipher** replaces each character with another character a fixed number of positions away in the alphabet (or digit range).
This implementation extends the original concept by **including digits (0–9)** in the encryption process.

For example, with a shift key of 3:

```
Plaintext : HELLO 123
Ciphertext: KHOOR 456
```

Spaces and symbols are left unchanged.

## 2. Mathematical Foundation

The Caesar Cipher uses **modular arithmetic** to wrap around alphabets and digits.
Each character set forms a **cyclic group** where shifting beyond the end loops back to the beginning.

Formulas:

```
Encryption:  C = (P + K) mod N
Decryption:  P = (C - K + N) mod N
```

Where:

- P = plaintext character’s numeric value
- C = ciphertext character’s numeric value
- K = key (shift value entered by user)
- N = size of character set

  * 26 for letters
  * 10 for digits

## 3. Programming Implementation

Language: **C**
This implementation:

- Encrypts and decrypts **letters and digits**.
- **Preserves case** of letters.
- **Ignores spaces and punctuation**, leaving them unchanged.
- Uses **user-input key (1–25)** for the shift.
- Provides both **encryption and decryption** options.

### Code Structure

- `encrypt()` handles shifting forward.
- `decrypt()` reverses the shift.
- Both functions iterate through each character and apply modular arithmetic.

```
if (islower(ch)) 
    text[i] = (ch - 'a' + key) % 26 + 'a';
else if (isupper(ch))
    text[i] = (ch - 'A' + key) % 26 + 'A';
else if (isdigit(ch))
    text[i] = (ch - '0' + key) % 10 + '0';
```

## 4. Security Analysis

Even though this cipher demonstrates the basic concept of encryption, it is **not secure** for any real-world use.

| Weakness | Description |
| -------- | ----------- |
| **Small keyspace** | Only 25 possible shifts (plus 9 for digits). Easily brute-forced. |
| **Predictable key** | Since the user manually enters the key, it can be guessed or reused. |
| **Frequency analysis** | Character frequency remains unchanged, making plaintext recovery trivial. |
| **No randomness or salt** | Each plaintext with the same key always encrypts to the same ciphertext. |
| **Linear arithmetic** | The relationship between plaintext and ciphertext is direct and reversible. |

> **Conclusion:**
> This cipher is useful for *educational purposes only* — it teaches substitution, modular arithmetic, and the foundations of modern cryptography, but it offers **no real security**.

---

## 5. How to Run

Sample interaction:

```
===Caesar Cipher Implementation===
1. Encrypt 
2. Decrypt 
Choose an option (1/2): 1
Enter your message: HELLO 123
Enter key (1-25): 3

Encrypted message: KHOOR 456
```

## 6. Learning Outcomes

From this project:

- Understood caesar cipher theory.
- Applied **modular arithmetic** in encryption/decryption.
- Implemented character handling using `ctype.h`.
- Identified **where classical ciphers fail in modern cryptography**.
- Learned how **security depends not just on algorithm, but on randomness, keyspace, and unpredictability**.

