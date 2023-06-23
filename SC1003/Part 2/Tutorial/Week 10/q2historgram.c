#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void freq(int ar[], int ar10[], int n);
void printer(int ar10[],int *min, int *max);
int main()
{
    int noinput, i, k, j, l;
    int array[100];
    int arrange[10];
    int min=0, max=9;

    printf("How many integers?\n");
    scanf("%d", &noinput);

    for (k=0;k<100;k++) {
    array[k] = 101;
    }
    for (j=0; j<10; j++) {
        arrange[j] = 0;
    }

    for (i=0; i < noinput; i++){
        array[i] = rand() %100;
    }

    srand(time(NULL));
    freq(array, arrange, noinput);

    printer(arrange, &min, &max);
    return 0;
}

void freq(int ar[], int ar10[],int n)
{
    int i, num;
    int a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, ifun=0, j=0;

    for (i=0; i<n; i++) {
        num = ar[i]/10;
        switch (num) {
        case (0):
            ar10[0]+=1;
            break;
        case (1):
            ar10[1]+=1;
            break;
        case(2):
            ar10[2]+=1;
            break;
        case(3):
            ar10[3]+=1;
            break;
        case(4):
            ar10[4]+=1;
            break;
        case(5):
            ar10[5]+=1;
            break;
        case(6):
            ar10[6]+=1;
            break;
        case(7):
            ar10[7]+=1;
            break;
        case(8):
            ar10[8]+=1;
            break;
        case(9):
            ar10[9]+=1;
            break;
        }
    }
}
void printer(int ar10[],int *min, int *max) {

    int i, j, k;

    for (k=0; k<10; k++) {
        printf("numbers: ");
        printf("%d ",ar10[k]);
    }

    printf("\n");

    for (i=0; i<10; i++){
        printf("%2d - %2d |", *min, *max);

        for (j=0; j<ar10[i]; j++) {
                printf("*");
        }
        *min+=10;
        *max+=10;
        printf("\n");
    }
}
