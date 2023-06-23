#include <string.h>
#include <stdio.h>
int main()
{
	/*edit*/
   /* Write your code here */
    int lettercount=0, numcount=0, i;
    char userin;

    printf("Enter your characters (# to end):\n");
    scanf("%c", &userin);

    while (userin != '#') {
        if ((userin>='A' && userin<='Z') || (userin>='a' && userin<='z'))
                lettercount+=1;

        else if (userin>='0' && userin<='9')
                numcount+=1;

        scanf("%c", &userin);
        }
    printf("The number of digits: %d\n", numcount);
    printf("The number of letters: %d\n", lettercount);

	/*end_edit*/
   return 0;
}
