#include <stdio.h>
#include <math.h>

int main()
{
    float a, out;

    char ptr[5], open='[', close=']', var='a';
    int len1=5;

    a = 3.0;
    out = pow(a,2);
    printf("%f\n", out);
    printf("%d\n", 96/10);


    sprintf(ptr, "%c%d%c%c", open, len1, var, close);
    printf("%s\n", ptr);
    return 0;

}
