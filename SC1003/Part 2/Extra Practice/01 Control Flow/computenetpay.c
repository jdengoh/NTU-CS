#include <stdio.h>
int main()
{
	/*edit*/
   /* Write your code here */
    int hours;
    float gross, tax, net;


    printf("Enter hours of work:\n");
    scanf("%d", &hours);

    if (hours<=40)
        gross = (float)hours * 6.0;
    else
        gross = (40.0*6.0) + ((float)(hours-40) * 9);

    printf("Gross pay=%.2f\n", gross);

    if (gross<=1000)
        tax = 0.1*(float)gross;

    else if(gross<=1500)
        tax = (0.1*1000.0)+(0.2*(gross-1000.0));

    else
        tax = (0.1*1000.0)+(0.2*500.0)+(0.3*(gross-1500.0));

    printf("Tax=%.2f\n",tax);

    net = gross-tax;

    printf("Net pay=%.2f\n",net);

	/*end_edit*/
   return 0;
}
