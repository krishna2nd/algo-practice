#include <stdio.h>

#define type unsigned long int

type fib(type n)
{
    type a = 0, b = 1, c, i;
    if (n <= 1)
        return n;
    for (i = 1; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

type fibR(type n)
{
    type a = 0, b = 1, c, i;
    if (n <= 1)
        return n;
    
    return fibR(n-1) + fibR(n-2);
}

int main()
{
    printf("%ld\n", fib(91));
    printf("%ld", fibR(91));
}
