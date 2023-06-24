#include <stdio.h>

int factorial(int n, int result)
{
    if (n == 0)
        return result;
    else
        return factorial(n - 1, n * result);
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int fibonacci(int n, int a, int b)
{
    if (n == 0)
        return a;
    else
        return fibonacci(n - 1, b, a + b);
}

int main()
{
    int num;

    printf("Enter a positive integer for factorial: ");
    scanf("%d", &num);

    int fact = factorial(num, 1);
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
        int fib = fibonacci(i, 0, 1);
        printf("%d ", fib);
    }
    printf("\n");

    return 0;
}
