#include <stdio.h>
#include <math.h>
int main()
{
	/*edit*/
   /* Write your code here */
    int a1, b1, c1, a2, b2, c2;
    float num1, num2, denom, x, y;

    printf("Enter a1,b1,c1,a2,b2,c2:\n");
    scanf("%d %d %d %d %d %d", &a1, &b1, &c1, &a2, &b2, &c2);

    denom = a1*b2 - a2*b1;

    if (denom == 0) {
        printf("Denominator is zero!");
    }

    else {
        num1 = b2*c1 - b1*c2;
        num2 = a1*c2 - a2*c1;

        x = num1/denom;
        y = num2/denom;
        printf("x=%.2f,y=%.2f", x, y);
    }
	/*end_edit*/
   return 0;
}
