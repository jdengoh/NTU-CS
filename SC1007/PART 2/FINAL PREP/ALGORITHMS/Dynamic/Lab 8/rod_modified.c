#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// memory
int *r;

void print_pos(int rlength, int first_cut[])
{
    if (rlength == 0)
        return;
    int pos = first_cut[rlength];
    printf("%d ", pos);
    print_pos(rlength - pos, first_cut);
}

int cr_bottom_up_dp_print(int *p, int n)
{
    r[0] = 0;
    int *cut;
    int temp;
    cut = (int *)malloc((n+1)*sizeof(int));
    cut[0]= 0;
    for (int i=1; i<=n; i++) {
        cut[i] = -1;
    }

    for (int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {

            temp = p[j] + r[i-j];

            if (temp>r[i]) {
                r[i] = temp;
                cut[i] = j;
            }
        }
    }
    int length = n;
    int slice;
    while(length>0) {
        slice = cut[length];
        printf("%d ", slice);
        length = length-slice;
    }

    return r[n];



}
    void main()
    {
        int n; // length of  rod
        int function;
        int i;
        int *p; // price list

        int price_list[10] = {0, 1, 4, 8, 9, 10, 17, 17, 20, 24}; // declare one more value to cover the index 0;

        n = sizeof(price_list) / sizeof(int) - 1;
        p = price_list;

        // allocate the memory array
        r = malloc(sizeof(int) * (n + 1));

        // set all memory elements to -1
        for (i = 0; i <= n; i++)
            r[i] = -1;

        printf("The maximun value is: %d \n", cr_bottom_up_dp_print(p, n));
    }
