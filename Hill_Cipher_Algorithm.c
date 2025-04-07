#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 3 // Size of the matrix (for a 3x3 matrix)

void getKeyMatrix(char key[], int keyMatrix[N][N])
{
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            keyMatrix[i][j] = (key[k] - 'A') % 26;
            k++;
        }
    }
}

void getMessageMatrix(char message[], int messageMatrix[], int len)
{
    for (int i = 0; i < len; i++)
    {
        messageMatrix[i] = (message[i] - 'A') % 26;
    }
}

void encrypt(int messageMatrix[], int keyMatrix[N][N], int cipherMatrix[], int len)
{
    for (int i = 0; i < N; i++)
    {
        cipherMatrix[i] = 0;
        for (int j = 0; j < N; j++)
        {
            cipherMatrix[i] += keyMatrix[i][j] * messageMatrix[j];
        }
        cipherMatrix[i] = cipherMatrix[i] % 26;
    }
}

void printMatrix(int matrix[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%c", matrix[i] + 'A');
    }
    printf("\n");
}

int main()
{
    char key[10], message[100];
    int keyMatrix[N][N], messageMatrix[N], cipherMatrix[N], len;

    printf("Enter key (3x3 matrix as a string, e.g. 'GYBNQKURP'): ");
    gets(key);

    // Get the key matrix
    getKeyMatrix(key, keyMatrix);

    printf("Enter message to encrypt (uppercase letters only): ");
    gets(message);
    len = strlen(message);

    // Make the message length a multiple of N by padding with 'X' if necessary
    if (len % N != 0)
    {
        int padding = N - (len % N);
        for (int i = 0; i < padding; i++)
        {
            message[len + i] = 'X';
        }
        message[len + padding] = '\0';
        len = strlen(message);
    }

    printf("Message length adjusted to %d (after padding with 'X')\n", len);

    printf("Encrypted message: ");
    for (int i = 0; i < len; i += N)
    {
        getMessageMatrix(&message[i], messageMatrix, N);
        encrypt(messageMatrix, keyMatrix, cipherMatrix, N);
        printMatrix(cipherMatrix, N);
    }

    return 0;
}