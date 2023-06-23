#include <stdio.h>
#include <string.h>
char *sweepSpace(char *str);
int main()
{
   char str[80], *p;

   printf("Enter the string: \n");
   fgets(str, 80, stdin);
   if (p=strchr(str,'\n')) *p = '\0';
   printf("sweepSpace(): %s\n", sweepSpace(str));
   return 0;
}
char *sweepSpace(char *str)
{
	/*edit*/
   /* Write your code here */
    int i, j;
    int len;
    len = strlen(str);
    for (i=0 ;i<len; i++) {
        if (str[i]!=' ') {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
    return str;
	/*end_edit*/
}
