#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a>b)? a:b;
}

int bottom_up_dp(int n, int *s, int *v, int C)
{
    int **table;
    table = (int **)malloc((n+1)*sizeof(int *));
    for (int i=0; i<=n; i++) {
        table[i] = (int *)malloc((C+1)*sizeof(int));
    }
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=C; j++) {
            table[i][j] = 0;
        }
    }

    for (int i=0; i<=n; i++) {
        for (int j=0; j<=C; j++) {

            if (j==0 || i==0) {
                table[i][j] = 0;
            }

            else if (s[i] <= j) {
                table[i][j] = max(table[i-1][j], table[i-1][j-s[i]] + s[i]);
            }

            else {
                table[i][j] = table[i-1][j];
            }
        }
    }

    //TRACING BACK
    int *result;
    result = (int *)malloc(n*sizeof(int));
    for (int i=0; i<n; i++) result[i] = 0;

    int item = n;
    int weight = C;

    while(item!=0 && weight!=0) {

        if (table[item][weight] == table[item-1][weight]) {
            result[item-1] = 0;
        }
        else {
            result[item-1] = 1;
            weight -= s[item];
        }

        item--;

    }

    for (int i=0; i<n; i++) printf("%d ", result[i]);

    printf("\n");

    return table[n][C];

}


int main ()
{
    int n,C;
    int function;
    int *s;
    int *v;
    int i,j;
    printf("Enter the number of items n:\n");
    scanf("%d",&n);
    printf("Enter the capacity C:\n");
    scanf("%d",&C);
    s = (int *) malloc(sizeof(int) * (n+1));
    v = (int *) malloc(sizeof(int) * (n+1));

    printf("Enter the sizes of items (as a list, separate by spacing:\n");
    for (i=1;i<=n;i++)
        scanf("%d",&s[i]);

    printf("Enter the values of items (as a list, separate by spacing:\n");
    for (i=1;i<=n;i++)
        scanf("%d",&v[i]);

    printf("The maximum value is: %d \n", bottom_up_dp(n,s,v,C));

}
