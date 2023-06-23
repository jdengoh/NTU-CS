#include <stdio.h>
#include <math.h>

struct circle{
    double radius;
    double x;
    double y;
};

int intersect(struct circle c1, struct circle c2);

int main()
{
    struct circle c1, c2;

    printf("Enter x and y coordinate for first circle:\n");
    scanf("%f %f",&c1.x, &c1.y);
    printf("Enter the radius:\n");
    scanf("%f", &c1.radius);
    printf("Enter x and y coordinate for the 2nd circle:\n");
    scanf("%f %f", &c2.x, &c2.y);
    printf("Enter the radius:\n");
    scanf("%f", &c2.radius);

    printf("return value : %d\n",intersect(c1,c2));
}

int intersect(struct circle c1, struct circle c2)
{
    int dist, sumrad;

    dist = sqrt((pow((c1.x - c2.x),2) + pow((c1.y-c2.y), 2))/2);
    sumrad = c1.radius + c2.radius;

    if (dist<=sumrad)
        return 1;
    else
        return 0;
}
