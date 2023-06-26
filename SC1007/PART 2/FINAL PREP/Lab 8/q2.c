#include <stdio.h>
#include <stdlib.h>

//memory
int *r;


int cr_bottom_up_dp_print(int *p, int n)
{
    //write your code here
    int temp;
    int slices;
    int *cut;

    cut = (int *)malloc(sizeof(int) * (n+1));
    cut[0] = 0;
    for (int i=1; i<=n; i++) {
        cut[i] = -1;
    }

    r[0] = 0;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {

            temp = p[j] + r[i-j];

            if (temp>r[i]) {
                r[i] = temp;
                cut[i] = j;
            }
        }
    }

    slices = n;
    while(slices>0) {
        printf("%d ", cut[slices]);
        slices -= cut[slices];
    }

    printf("\n");

    return r[n];

}


void main ()
{
    int n;      //length of  rod
    int function;
    int i;
    int *p;     //price list

    int price_list[10] = {0,1,4,8,9,10,17,17,20,24}; //declare one more value to cover the index 0;

    n = sizeof(price_list) / sizeof(int) - 1;
    p = price_list;


    //allocate the memory array
    r = malloc(sizeof(int) * (n+1));


    //set all memory elements to -1
    for (i=0; i<=n; i++)
        r[i] = -1;

    printf("The maximun value is: %d \n", cr_bottom_up_dp_print(p,n));
}
