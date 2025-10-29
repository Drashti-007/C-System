# Cryptography

It's a technique of securing information and communication using code to ensure *confidentiality*, *integrity*, and *authentication*. 
Cryptography prevents unauthorized access to information.

<img width="1920" height="1080" alt="Plain text" src="https://github.com/user-attachments/assets/5507ed35-18ba-4037-8e44-eeb449ec6f3c" />

These algorithm are used for cryptographic key generation, digital signature/signing, and verification to protect data privacy, web browsiong
on the internet and to protect confidential transactions such as credict card and debit card transactions.

## Types of Cryptography
- Symmetric Key Cryptography
   - Same key is used for both encryption and decryption.
   - Example: Caesar Cipher, DES, AES.
   - Faster but less secure if key is leaked.

- Asymmetric Key Cryptography
   - Two keys: Public (shared) and Private (kept secret)
   - Sender encrypts using public key, receiver decrypt using private key.
   - Example: RSA, Elliptic Curve Cryptography.
   - More secure, but slower than symmetric.
   
## Symmetric Cryptography Algorithms

| Algorithms | Description | Strength | Weaknesses |
|------------|-------------|----------|------------|
| Caesar Cipher| Shifts each letter by a fixed number ( A -> D, B -> E, etc ) | Easy to implement | Easy to break (bruteforce) |
| Substitution Cipher | Each letter replaced with another symbol/letter | Slightly stronger | Still guessable with frequency analysis |
| XOR Encryption | Performs bitwise XOR operation with a key | Fast, used in programming | Weak if key is small |
| DES (Data Encryption Standard) | Uses 56-bit key encrypts data in blocks | Fast | Outdated (can be brute-forced) |
| AES (Advanced Encryption Standard) | Modern standard 128/192/256-bit keys | Extremely secure | Slower on the weak devices |

