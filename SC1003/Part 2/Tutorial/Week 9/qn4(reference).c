#include <stdio.h>
#include <math.h>

float finddist(float *a, float *b, float *c, float *d);

int main()
{
    float x2, x1, y2, y1, dist;

    printf("Enter the coordinates of the first point:\n");
    scanf("%f",&x1);
    scanf("%f",&y1);

    printf("Enter the coordinates of the second point:\n");
    scanf("%f", &x2);
    scanf("%f", &y2);

    dist = finddist(&x1,&y1,&x2,&y2);

    printf("The distance is %.2f", dist);

    return 0;
}

float finddist(float *a, float *b, float *c, float *d)
{
    float distance, coord2sq, coord1sq;

    coord1sq = pow((*c-*a),2);
    printf("%.2f\n", coord1sq);

    coord2sq = pow((*d-*b),2);
    printf("%.2f\n", coord2sq);

    distance = sqrt((coord1sq+coord2sq));

    return distance;
}
