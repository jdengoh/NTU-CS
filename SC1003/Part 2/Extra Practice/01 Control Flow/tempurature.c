#include <stdio.h>
int main()
{

	/*edit*/
    /* Write your code here */
    int in;
    float celsius;

    printf("Enter the temperature in degree F:\n");
    scanf("%d", &in);


    while(in!=-1) {

        celsius = ((5.0/9.0)*((float)in-32.0));
        printf("Converted degree in C: %.2f\n", celsius);

        printf("Enter the temperature in degree F:\n");
        scanf("%d", &in);
    }

	/*end_edit*/

   return 0;
}
