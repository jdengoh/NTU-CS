#include <stdio.h>
int main()
{
	/*edit*/
   /* Write your code here */

    float listprice, disprice, luxtax, gst, finprice, coeprice, final;
    int coetype;

    printf("Please enter the list price: \n");
    scanf("%f", &listprice);

    disprice = 0.9*listprice;
    gst = 0.03*disprice;

    if (disprice >=100000.0)
        luxtax = 0.1*disprice;
    else
        luxtax = 0;

    finprice = disprice + gst + luxtax;

    printf("Please enter the category: \n");
    scanf("%d", &coetype);

    switch (coetype) {

        case 1:
            coeprice = 70000.0;
            break;
        case 2:
            coeprice = 80000.0;
            break;
        case 3:
            coeprice = 23000.0;
            break;
        case 4:
            coeprice = 600.0;
            break;
    }

    final = finprice + coeprice;

    printf("Total price is $%.2f", final);

	/*end_edit*/
   return 0;
}
