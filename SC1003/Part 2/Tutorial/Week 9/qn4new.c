#include <stdio.h>
#include <math.h>

void finddist(float x1, float y1, float x2, float y2, float*result);

int main()
{
    float*result;
    float x2, x1, y2, y1, dist;

    /* "pointing" pointer variable, result, to memory address of dist */
    result = &dist;

    printf("Enter the coordinates of the first point:\n");
    scanf("%f",&x1);
    scanf("%f",&y1);

    printf("Enter the coordinates of the second point:\n");
    scanf("%f", &x2);
    scanf("%f", &y2);

    /* passing pointer variable result into function */

    finddist(x1,y1,x2,y2,result);

    printf("The distance is %.2f\n", *result);

    /*help us check*/
    printf("\n");
    printf("Checking ptr and variables\n");
    printf("float variable dist value is %.2f\n", dist);
    printf("pointer variable *result value is %.2f\n", *result);

    return 0;
}

/* pointer variable result, is "passed" into pointer variable, ptr, in the function parameter */

void finddist(float x1, float y1, float x2, float y2, float*ptr)
{
    float coord2sq, coord1sq;

    coord1sq = pow((x2-x1),2);
    coord2sq = pow((y2-y1),2);

    *ptr = sqrt((coord1sq+coord2sq));
}
