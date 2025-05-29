#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int eulerTotient(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            result -= result / i;
        }
    }
    if (n > 1)
    {
        result -= result / n;
    }
    return result;
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Euler's Totient of %d is %d\n", n, eulerTotient(n));

    return 0;
}