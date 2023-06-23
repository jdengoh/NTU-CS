#include <stdio.h>
#define INIT_VALUE -1000
int findAr1D(int size, int ar[], int target);
int main()
{
int ar[20];
int size, i, target, result = INIT_VALUE;
printf("Enter array size: \n");
scanf("%d", &size);
printf("Enter %d data: \n", size);
for (i=0; i<=size-1; i++)
scanf("%d", &ar[i]);
printf("Enter the target number: \n");
scanf("%d", &target);
result = findAr1D(size, ar, target);
if (result == -1)
printf("findAr1D(): Not found\n");
else
printf("findAr1D(): %d", result);
return 0;
}
int findAr1D(int size, int ar[], int target)
{
    /* Write your code here */
    int j, count = 0;

    for (j=0; j<size; j++) {
        if (ar[j] == target)
            return count;
        count += 1;
    }

    count = -1;
    return count;
}
