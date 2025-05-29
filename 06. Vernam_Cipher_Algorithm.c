#include <stdio.h>
#include <string.h>

void encrypt(char message[], char key[])
{
    for (int i = 0; message[i] != '\0'; ++i)
    {
        message[i] = message[i] ^ key[i];
    }
}

void decrypt(char message[], char key[])
{
    encrypt(message, key); // Encryption and decryption are the same in Vernam Cipher
}

int main()
{
    char message[100], key[100];

    printf("Enter message: ");
    gets(message);
    printf("Enter key (same length as message): ");
    gets(key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}