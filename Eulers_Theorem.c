#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    if (gcd(a, b) == 1)
    {
        printf("%d and %d are relatively prime.\n", a, b);
    }
    else
    {
        printf("%d and %d are not relatively prime.\n", a, b);
    }

    return 0;
}