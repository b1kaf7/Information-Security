#include <stdio.h>

#include <string.h>

char key[26] = "QWERTYUIOPLKJHGFDSAZXCVBNM";

void encrypt(char message[])
{
    for (int i = 0; message[i] != '\0'; ++i)
    {
        char ch = message[i];
        if (ch >= 'a' && ch <= 'z')
        {
            message[i] = key[ch - 'a'];
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            message[i] = key[ch - 'A'];
        }
    }
}

void decrypt(char message[])
{
    for (int i = 0; message[i] != '\0'; ++i)
    {
        char ch = message[i];
        for (int j = 0; j < 26; ++j)
        {
            if (key[j] == ch)
            {
                message[i] = 'A' + j;
                break;
            }
        }
    }
}

int main()
{
    char message[100];

    printf("Enter a message to encrypt: ");
    gets(message);

    encrypt(message);
    printf("Encrypted message: %s\n", message);

    decrypt(message);
    printf("Decrypted message: %s\n", message);

    return 0;
}