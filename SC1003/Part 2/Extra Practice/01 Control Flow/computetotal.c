#include <stdio.h>
int main()
{
	/*edit*/
   /* Write your code here */
    int lines, l1, l1in, i, j, sum1;
    printf("Enter number of hello lines: \n");
    scanf("%d", &lines);

    for (i=1; i<=lines;i++) {

        sum1 = 0;

        printf("Enter line %d: \n", i);
        scanf("%d", &l1);

        for (j=1; j<=l1; j++) {

            scanf("%d", &l1in);

            sum1+=l1in;
        }

        printf("Total: %d\n", sum1);
    }

	/*end_edit*/
   return 0;
}
