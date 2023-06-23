#include <stdio.h>
#define SIZE 4

void transpose2D (int ar[][SIZE], int rowSize, int colSize);

int main()
{
    int ar[4][4] = {1,2,3,4, 5,1,2,2, 6,3,4,4, 7,5,6,7};
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
    int i,j, temp,k,l;
    int prvsar[4][4];
    for (k=0; k<rowSize; k++) {
        for (l=0; l<colSize; l++) {
                prvsar[k][l] = ar[k][l];
        }
    }

    for (i=0; i<rowSize; i++) {
        for (j=0; j<colSize; j++) {
            if (ar[i][j] == prvsar[i][j]) {
                temp = ar[i][j];
                ar[i][j] = ar[j][i];
                ar[j][i] = temp;
            }
        }
    }

}
