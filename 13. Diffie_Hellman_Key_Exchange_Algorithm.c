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
    long long p = 23, g = 5, a, b, A, B, secretA, secretB;

    printf("Enter private key of A: ");
    scanf("%lld", &a);
    printf("Enter private key of B: ");
    scanf("%lld", &b);

    A = power(g, a, p);
    B = power(g, b, p);

    secretA = power(B, a, p);
    secretB = power(A, b, p);

    printf("Shared secret by A: %lld\n", secretA);
    printf("Shared secret by B: %lld\n", secretB);

    return 0;
}