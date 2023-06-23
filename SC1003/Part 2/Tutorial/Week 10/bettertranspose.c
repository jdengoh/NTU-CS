#include <stdio.h>
#define SIZE 10

void transpose2D (int ar[][SIZE], int rowSize, int colSize);

int main()
{
    int ar[SIZE][SIZE] = { {1,2,3,4}, {5,1,2,2}, {6,3,4,4}, {7,5,6,7}};
    int k,l;

    transpose2D(ar, 4, 4);

    for (k=0;k<4;k++) {
        for (l=0;l<4;l++){
            printf("%d", ar[k][l]);
        }
        printf("\n");
    }
}

void transpose2D(int ar[][SIZE], int rowSize, int colSize)
{
    int i,j,temp;
    for (i=1; i<rowSize; i++) {
        for (j=0; j<i; j++) {
            temp = ar[i][j];
            ar[i][j] = ar[j][i];
            ar[j][i] = temp;
        }
    }
}
