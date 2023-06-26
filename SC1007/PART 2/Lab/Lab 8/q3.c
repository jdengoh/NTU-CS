#include <stdio.h>
#include <stdlib.h>

int waysToScore(int n, int* score){
{
    //write your code here
}

 
void main ()
{
    int n;

    int score[3] = {3,5,10}; 

    printf("Enter the value of N: ");
    scanf("%d",&n);


    printf("The number of ways to reach to a score of %d is: %d \n",n, waysToScore(n,score));
}
