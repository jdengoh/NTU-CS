#include <stdio.h>

int main()
{
    int line, num, i, count, sum;
    double average;

    printf("Enter the number of lines\n");
    scanf("%d", &line);

    for (i=1; i<=line; i++)
    {
        sum = 0;
        count = 0;

        printf("Enter line %d\n", i);
        scanf("%d", &num);
        while (num != -1)
        {
            sum += num;
            count += 1;
            scanf("%d", &num);
        }
        printf("\n");
        average = (double)sum / (double)count;
        printf("%.2f\n", average);
    }
    return 0;
}
