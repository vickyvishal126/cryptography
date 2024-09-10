#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

void generate_cipher_alphabet(const char *keyword, char cipher_alphabet[ALPHABET_SIZE]) {
    int used[ALPHABET_SIZE] = {0};
    int i, j = 0;
    
    for (i = 0; keyword[i] != '\0'; i++) {
        char ch = toupper(keyword[i]);
        if (!used[ch - 'A']) { 
            cipher_alphabet[j++] = ch;
            used[ch - 'A'] = 1;
        }
    }

    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (!used[i]) {
            cipher_alphabet[j++] = 'A' + i;
        }
    }
}

void encrypt(const char *plaintext, const char cipher_alphabet[ALPHABET_SIZE], char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char ch = toupper(plaintext[i]);
            ciphertext[i] = cipher_alphabet[ch - 'A'];
        } else {
            ciphertext[i] = plaintext[i]; 
        }
    }
    ciphertext[i] = '\0'; 
}

void decrypt(const char *ciphertext, const char cipher_alphabet[ALPHABET_SIZE], char *plaintext) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char ch = toupper(ciphertext[i]);
            for (int j = 0; j < ALPHABET_SIZE; j++) {
                if (cipher_alphabet[j] == ch) {
                    plaintext[i] = 'A' + j;
                    break;
                }
            }
        } else {
            plaintext[i] = ciphertext[i]; 
        }
    }
    plaintext[i] = '\0'; 
}

int main() {
    char keyword[] = "CIPHER";
    char cipher_alphabet[ALPHABET_SIZE];
    char plaintext[100];
    char ciphertext[100];
    char decryptedtext[100];

    generate_cipher_alphabet(keyword, cipher_alphabet);

    printf("Cipher alphabet: ");
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        printf("%c", cipher_alphabet[i]);
    }
    printf("\n");

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 

    encrypt(plaintext, cipher_alphabet, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, cipher_alphabet, decryptedtext);
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}

