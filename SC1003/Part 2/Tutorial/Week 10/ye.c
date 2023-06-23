#include <stdio.h>
#include <stdlib.h>
int freq_distr(int N);
void print_distr(int A);

int num[10][10];
int A[10];

int main()
{
    //get input from user//
    int N;
    printf("no. of inputs(N): ");
    scanf("%d", &N);
    A[10] = freq_distr(N);
    print_distr(A);
}
int freq_distr(int N)
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
                int A[0]++;
            }
            else if (10 <= num[i][j] <= 19)
            {
                int A[1]++;
            }
            else if (20 <= num[i][j] <= 29){
                int A[2]++;
            }
            else if (30 <= num[i][j] <= 39){
                int A[3]++;
            }
            else if (40 <= num[i][j] <= 49){
                int A[4]++;
            }
            else if (50 <= num[i][j] <= 59){
                int A[5]++;
            }
            else if (60 <= num[i][j] <= 69){
                int A[6]++;
            }
            else if (70 <= num[i][j] <= 79){
                int A[7]++;
            }
            else if (80 <= num[i][j] <= 89){
                int A[8]++;
            }
            else if (90 <= num[i][j] <= 99){
                int A[9]++;
            }
            return A;
        }
    }
}
void print_distr(int A)
{
    int x=0, y=0;
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
