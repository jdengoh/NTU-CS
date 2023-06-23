#include <stdio.h>
#include <stdlib.h>
void freq_distr(int N, int A[]);
void print_distr(int A[]);

int num[10][10];
int A[10];

int main()
{
    //get input from user//
    int N;
    int array[10];
    printf("no. of inputs(N): ");
    scanf("%d", &N);
    freq_distr(N, array);
    print_distr(array);
    return 0;
}

void freq_distr(int N, int A[])
{
    /*calculate how many rows and columns needed
    if user inputs 9, 1 row 10 columns
    input 55, 6 rows 10 columns*/

    int row = (N/10)%10;
    int col = N%10;

    /*array may be partially initialised and will have
    extra 0s added to the final product*/
    int spill = (10-col);
    if (col>0){
        row++;
    }

    //allocate random number to 2-d array//
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<10; j++)
        {
            num[i][j] = rand()%100;
        }
    }

    for (int i=0; i<row; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (0 <= num[i][j] <= 9)
            {
                A[0]++;
            }
            else if (10 <= num[i][j] <= 19)
            {
                A[1]++;
            }
            else if (20 <= num[i][j] <= 29){
                A[2]++;
            }
            else if (30 <= num[i][j] <= 39){
                A[3]++;
            }
            else if (40 <= num[i][j] <= 49){
                A[4]++;
            }
            else if (50 <= num[i][j] <= 59){
                A[5]++;
            }
            else if (60 <= num[i][j] <= 69){
                A[6]++;
            }
            else if (70 <= num[i][j] <= 79){
                A[7]++;
            }
            else if (80 <= num[i][j] <= 89){
                A[8]++;
            }
            else if (90 <= num[i][j] <= 99){
                A[9]++;
            }
        }
    }
}
void print_distr(int A[])
{
    int x=0, y=0, var;
    for (int i=0; i<10; i++){
        printf("%d0 - %d9 |", x, y);
        x++;
        y++;
        for (int j=0; j<A[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
