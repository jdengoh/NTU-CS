#include <stdio.h>

int product(int m, int n)
{
    int result;

    result = m*n;

    return result;
}

int main()
{
    int a, b, c;

    a=2;
    b=3;
    c = product(a,b);

    printf("%d", c);

    return 0;
}
