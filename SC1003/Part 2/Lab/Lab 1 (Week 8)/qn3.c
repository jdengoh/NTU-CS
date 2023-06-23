#include <stdio.h>

int height, i, j, num;



int main()
{
    printf("Enter the height\n");
    scanf("%d", &height);

    printf("Pattern:\n");

    num = 1;

    for (i=1; i<=height; i++){

        for (j=1; j<=i; j++){

            num = (num % 3);

            if (num == 0)
                printf("3");

            else
                printf("%d", num);
        }

    printf("\n");
    num += 1;

    }
    return 0;
}
