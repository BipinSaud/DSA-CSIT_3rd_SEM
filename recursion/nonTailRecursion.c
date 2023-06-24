#include <stdio.h>

int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int num;

    printf("Enter a positive integer for factorial: ");
    scanf("%d", &num);

    int fact = factorial(num);
    printf("Factorial of %d: %d\n", num, fact);

    int num1, num2;

    printf("Enter two positive integers for GCD: ");
    scanf("%d %d", &num1, &num2);

    int gcdVal = gcd(num1, num2);
    printf("GCD of %d and %d: %d\n", num1, num2, gcdVal);

    printf("Enter a positive integer for Fibonacci series: ");
    scanf("%d", &num);

    printf("Fibonacci series up to %d: ", num);
    for (int i = 0; i < num; i++)
    {
        int fib = fibonacci(i);
        printf("%d ", fib);
    }
    printf("\n");

    return 0;
}
