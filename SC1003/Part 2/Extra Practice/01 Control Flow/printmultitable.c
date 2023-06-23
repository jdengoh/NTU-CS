#include <stdio.h>
int main()
{
	/*edit*/
   /* Write your code here */
    int userin, num, i, j;

    printf("Enter a number (between 1 and 9):\n");
    scanf("%d", &userin);
    printf("Multiplication Table: \n");
    for (num = 1; num<=userin; num++) {

        printf(" %d", num);

    }
    printf("\n");

    for (i=1; i<=userin; i++) {

        printf("%d ", i);

        for (j=1; j<=i; j++) {
            printf("%d ", j*i);
        }

        printf("\n");
    }

	/*end_edit*/
   return 0;
}
