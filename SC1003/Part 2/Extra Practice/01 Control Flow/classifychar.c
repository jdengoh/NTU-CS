#include <stdio.h>
int main()
{
	/*edit*/
   /* Write your code here */
    char userin;

    printf("Enter a character:\n");
    scanf("%c", &userin);

    if (userin>='A' && userin<='Z')
        printf("Upper case letter");

    else if (userin>='a' && userin<='z')
        printf("Lower case letter");

    else if (userin>='0' && userin<='9')
        printf("Digit");

    else
        printf("Other character");

	/*end_edit*/
   return 0;
}
