#include <stdio.h>
#include <math.h>

float finddist(float x1, float y1, float x2, float y2);

int main()
{
    float x2, x1, y2, y1, dist;

    printf("Enter the coordinates of the first point:\n");
    scanf("%f",&x1);
    scanf("%f",&y1);

    printf("Enter the coordinates of the second point:\n");
    scanf("%f", &x2);
    scanf("%f", &y2);

    dist = finddist(x1,y1,x2,y2);

    printf("The distance is %.2f", dist);

    return 0;
}

float finddist(float x1, float y1, float x2, float y2)
{
    float distance, coord2sq, coord1sq;

    coord1sq = pow((x2-x1),2);
    printf("%.2f\n", coord1sq);

    coord2sq = pow((y2-y1),2);
    printf("%.2f\n", coord2sq);

    distance = sqrt((coord1sq+coord2sq));

    return distance;
}
