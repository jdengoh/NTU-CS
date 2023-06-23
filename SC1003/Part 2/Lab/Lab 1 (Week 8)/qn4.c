#include <stdio.h>

int i, denom;
float numer, sum, xin;

int main()
{
    printf("Enter X:\n");
    scanf("%f", &xin);

    numer = xin;
    denom = 1;
    sum = 1+ numer/denom;

    for (i=1; i<10; i++){

        numer *= xin;
        denom *= i+1;

        sum += numer/denom;

    }
    printf("Result = %.2f", sum);
    return 0;
}
