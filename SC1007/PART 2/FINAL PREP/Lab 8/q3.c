#include <stdio.h>
#include <stdlib.h>

int waysToScore(int n, int* score)
{
    //write your code here

    int count=0;
    int temp;

    if (n<0) return 0;

    else if (n==0) return 1;

    for (int i=0; i<3; i++) {
        temp = n-score[i];
        count += waysToScore(temp, score);
    }
    return count;
}


void main ()
{
    int n;

    int score[3] = {3,5,10};

    printf("Enter the value of N: ");
    scanf("%d",&n);


    printf("The number of ways to reach to a score of %d is: %d \n",n, waysToScore(n,score));
}
