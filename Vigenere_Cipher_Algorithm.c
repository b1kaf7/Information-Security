#include <stdio.h>
#include <string.h>

void encrypt(char message[], char key[])
{
    int i, j;
    int len = strlen(message);
    int keyLen = strlen(key);
    for (i = 0, j = 0; i < len; ++i)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((message[i] - 'a' + key[j % keyLen] - 'a') % 26) + 'a';
            j++;
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = ((message[i] - 'A' + key[j % keyLen] - 'A') % 26) + 'A';
            j++;
        }
    }
}

void decrypt(char message[], char key[])
{
    int i, j;
    int len = strlen(message);
    int keyLen = strlen(key);
    for (i = 0, j = 0; i < len; ++i)
    {
        if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = ((message[i] - 'a' - (key[j % keyLen] - 'a') + 26) % 26) + 'a';
            j++;
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = ((message[i] - 'A' - (key[j % keyLen] - 'A') + 26) % 26) + 'A';
            j++;
        }
    }
}

int main()
{
    char message[100], key[50];
    printf("Enter message: ");
    gets(message);
    printf("Enter key: ");
    gets(key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}