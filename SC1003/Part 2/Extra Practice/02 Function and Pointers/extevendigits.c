#include <stdio.h>
#define INIT_VALUE 999
int extEvenDigits1(int num);
void extEvenDigits2(int num, int *result);
int main()
{
   int number, result = INIT_VALUE;

   printf("Enter a number: \n");
   scanf("%d", &number);
   printf("extEvenDigits1(): %d\n", extEvenDigits1(number));
   extEvenDigits2(number, &result);
   printf("extEvenDigits2(): %d\n", result);
   return 0;
}
int extEvenDigits1(int num)
{
	/*edit*/
   /* Write your code here */
    int multiple=1, i, lastdigit, result=0;
    while (num != 0) {
        lastdigit = num%10;
        if (lastdigit%2==0) {
            result += (lastdigit*multiple);
            multiple *= 10;
        }
        num /= 10;
    }
    if (result == 0) {
        result = -1;
        return result;
    }
    else
        return result;

	/*end_edit*/
}
void extEvenDigits2(int num, int *result)
{
	/*edit*/
   /* Write your code here */
    int multiple=1, i, lastdigit;
    *result = 0;

    while (num != 0) {
        lastdigit = num%10;
        if (lastdigit%2==0) {
            *result += (lastdigit*multiple);
            multiple *= 10;
        }
        num /= 10;
    }
    if (*result == 0) {
        *result = -1;
    }

	/*end_edit*/
}
