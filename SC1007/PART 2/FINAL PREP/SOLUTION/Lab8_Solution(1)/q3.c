#include <stdio.h>
#include <stdlib.h>

//Recursive approach
//int waysToScore(int n,int* score)
//{
//    if(n<0) return 0;
//    if(n==0) return 1;
//
//    return waysToScore(n-score[0],score) +
//           waysToScore(n-score[1],score) +
//           waysToScore(n-score[2],score);

//}

//bottom up DP approach
int waysToScore(int n, int* score){
    int* arr;
    arr = (int*) malloc(sizeof(int)*n + 1);
    int i;
    for(i=0;i<=n;i++) arr[i]=0;

    arr[0] = 1;

    for(i=1;i<=n;i++)
    {
        if(i-score[0]>=0) arr[i] += arr[i-score[0]];

        if(i-score[1]>=0) arr[i] += arr[i-score[1]];

        if(i-score[2]>=0) arr[i] += arr[i-score[2]];

    }

    return arr[n];

}


void main ()
{
    int n;

    int score[3] = {3,5,10};

    printf("Enter the value of N: ");
    scanf("%d",&n);


    printf("The number of ways to reach to a score of %d is: %d \n",n, waysToScore(n,score));
}
