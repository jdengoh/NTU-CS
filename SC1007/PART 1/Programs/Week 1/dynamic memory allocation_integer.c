///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Purpose: Dynamically allocate memory space for an integer */

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *i;                                     // int *i is a pointer to an integer
    i = malloc(sizeof(int));                    // Reserve the requested memory (sizeof(int)) and returns a pointer to it

    if (i == NULL)                              // The returned pointer should be NULL in case of failure.
        printf("Uh oh.\n");

    printf("Enter an integer: ");
    scanf("%d", i);                             // Read the integer which entered by the user
    printf("The magic number is %d\n", *i);     // Print the integer
    return 0;
}
