#include <stdio.h>
#define SIZE 10

void reduceMatrix2D (int ar[][SIZE], int rowSize, int colSize);

int main()
{
    int ar[SIZE][SIZE] = {{4,3,8,6}, {9,0,6,5}, {5,1,2,4}, {9,8,3,7}};
    int k,l;

    reduceMatrix2D(ar, 4, 4);

    for (k=0;k<4;k++) {
        for (l=0;l<4;l++){
            printf("%2d ", ar[k][l]);
        }
        printf("\n");
    }
}

void reduceMatrix2D(int ar[][SIZE], int rowSize, int colSize)
{
    int i,j,sum;
    for (i=0; i<colSize; i++) {
        sum=0;
        for (j=3; j>=i; j--) {
            sum += ar[j][i];
            ar[j][i] = 0;
        }
        ar[i][i] = sum;
    }g
}
