#include <stdio.h>
int square1(int num);
void square2(int num, int *result);

int main()
{
    int number, result=0;
    printf("Enter the number: \n");

    scanf("%d", &number);
    printf("square1(): %d\n", square1(number));

    square2(number, &result);
    printf("square2(): %d\n", result);

    return 0;
}
int square1(int num)
{
    /* Write your code here */
    int i, sum=0,j=1;

    for (i=1;i<=num;i++) {

        sum += j;
        j += 2;
        }
    return sum;
}
void square2(int num, int *result)
{
    /* Write your code here */
    int i, j=1;

    for (i=1;i<=num;i++) {

        *result += j;
        j += 2;
        }
}
