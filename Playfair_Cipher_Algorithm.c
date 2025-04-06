#include <stdio.h>
#include <string.h>

#define SIZE 5

void prepareKeyTable(char key[], char keyTable[SIZE][SIZE])
{
    int map[26] = {0};
    int i, j, k;
    int len = strlen(key);

    for (i = 0, k = 0; i < len; ++i)
    {
        if (key[i] != 'j' && map[key[i] - 'a'] == 0)
        {
            keyTable[k / SIZE][k % SIZE] = key[i];
            map[key[i] - 'a'] = 1;
            ++k;
        }
    }

    for (i = 0; i < 26; ++i)
    {
        if (i != ('j' - 'a') && map[i] == 0)
        {
            keyTable[k / SIZE][k % SIZE] = i + 'a';
            ++k;
        }
    }
}

void search(char keyTable[SIZE][SIZE], char a, char b, int arr[])
{
    int i, j;

    if (a == 'j')
        a = 'i';
    else if (b == 'j')
        b = 'i';

    for (i = 0; i < SIZE; ++i)
    {
        for (j = 0; j < SIZE; ++j)
        {
            if (keyTable[i][j] == a)
            {
                arr[0] = i;
                arr[1] = j;
            }
            if (keyTable[i][j] == b)
            {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

void encrypt(char str[], char keyTable[SIZE][SIZE])
{
    int i, a[4];

    for (i = 0; i < strlen(str); i += 2)
    {
        search(keyTable, str[i], str[i + 1], a);

        if (a[0] == a[2])
        {
            str[i] = keyTable[a[0]][(a[1] + 1) % SIZE];
            str[i + 1] = keyTable[a[0]][(a[3] + 1) % SIZE];
        }
        else if (a[1] == a[3])
        {
            str[i] = keyTable[(a[0] + 1) % SIZE][a[1]];
            str[i + 1] = keyTable[(a[2] + 1) % SIZE][a[1]];
        }
        else
        {
            str[i] = keyTable[a[0]][a[3]];
            str[i + 1] = keyTable[a[2]][a[1]];
        }
    }
}

int main()
{
    char key[26], str[100];
    char keyTable[SIZE][SIZE];

    printf("Enter key: ");
    gets(key);
    printf("Enter message: ");
    gets(str);

    prepareKeyTable(key, keyTable);
    encrypt(str, keyTable);

    printf("Encrypted message: %s\n", str);

    return 0;
}