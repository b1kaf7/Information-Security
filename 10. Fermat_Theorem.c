#include <stdio.h>
#include <stdlib.h>

int isPrime(int n)
{
    if (n <= 1)
        return 0;

    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    printf("Enter a number to check if it's prime: ");
    scanf("%d", &n);

    if (isPrime(n))
    {
        printf("%d is prime.\n", n);
    }
    else
    {
        printf("%d is not prime.\n", n);
    }
    return 0;
}