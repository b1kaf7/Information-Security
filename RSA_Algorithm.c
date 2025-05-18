#include <stdio.h>
#include <math.h>

long long power(long long base, long long exp, long long mod)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main()
{
    long long p = 61, q = 53, n, phi, e = 17, d, message, ciphertext, decryptedMessage;

    n = p * q;
    phi = (p - 1) * (q - 1);
    d = 2753; // Example, d is the modular inverse of e (calculated offline)

    printf("Enter message to encrypt: ");
    scanf("%lld", &message);

    ciphertext = power(message, e, n);
    decryptedMessage = power(ciphertext, d, n);

    printf("Encrypted message: %lld\n", ciphertext);
    printf("Decrypted message: %lld\n", decryptedMessage);

    return 0;
}