#include <stdio.h>
#include <stdlib.h>

int ProcessArray (int *listA, int x, int n);

int main() {
    int in;
    int num[7];
    num[0] = 1;
    num[1] = 2;
    num[2] = 4;
    num[3] = 5;
    num[4] = 6;
    num[5] = 7;
    num[6] = 8;
    num[7] = 9;
    num[8] = 10;

    scanf("%d", &in);

    printf("ans is %d", ProcessArray (&num, in, 8));

}

int ProcessArray (int *listA, int x, int n) {

    int i,j,k;

    i = 0;
    j = n-1;

    do {
        k = (i+j)/2;
        if (x <= listA[k])
            j = k-1;
        if (listA[k] <= x)
            i = k+1;
    } while (i<=j);

    if (listA[k] == x)
        return(k);

    else
        return -1;


}
