#include <stdio.h>
#include <string.h>

char key[26] = "QWERTYUIOPLKJHGFDSAZXCVBNM";

void encrypt(char *msg)
{
    for (int i = 0; msg[i]; i++)
    {
        if (msg[i] >= 'A' && msg[i] <= 'Z')
            msg[i] = key[msg[i] - 'A'];
        else if (msg[i] >= 'a' && msg[i] <= 'z')
            msg[i] = key[msg[i] - 'a'];
    }
}

void decrypt(char *msg)
{
    for (int i = 0; msg[i]; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (msg[i] == key[j])
            {
                msg[i] = 'A' + j;
                break;
            }
        }
    }
}

int main()
{
    char msg[100];

    printf("Enter message: ");
    fgets(msg, sizeof(msg), stdin);
    msg[strcspn(msg, "\n")] = '\0';

    encrypt(msg);
    printf("Encrypted: %s\n", msg);

    decrypt(msg);
    printf("Decrypted: %s\n", msg);

    return 0;
}