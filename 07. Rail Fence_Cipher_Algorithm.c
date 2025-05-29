#include <stdio.h>
#include <string.h>

void encrypt(char message[], int key)
{
    int len = strlen(message);
    char rail[key][len];
    for (int i = 0; i < key; ++i)
        for (int j = 0; j < len; ++j)
            rail[i][j] = '\n';

    int row = 0, direction = 1;
    for (int i = 0; i < len; ++i)
    {
        rail[row][i] = message[i];
        row += direction;

        if (row == key || row == 0)
            direction *= -1;
    }

    printf("Encrypted message: ");
    for (int i = 0; i < key; ++i)
        for (int j = 0; j < len; ++j)
            if (rail[i][j] != '\n')
                printf("%c", rail[i][j]);
}

int main()
{
    char message[100];
    int key;
    printf("Enter message: ");
    gets(message);
    printf("Enter key: ");
    scanf("%d", &key);

    encrypt(message, key);

    return 0;
}