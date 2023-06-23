#include <stdio.h>

int main()
{
    int id, score;

    printf("Enter Student ID:\n");
    scanf("%d", &id);

    while (id != -1)
    {
        printf("Enter Mark:\n");
        scanf("%d", &score);

        switch((score+5)/10)

        {

        case 10:
        case 9:
        case 8:
            printf("A\n");
            break;
        case 7:
            printf("B\n");
            break;
        case 6:
            printf("C\n");
            break;
        case 5:
            printf("D\n");
            break;
        default:
            printf("F\n");

        }
    printf("Enter student ID:\n");
    scanf("%d", &id);
    }

return 0;
}
