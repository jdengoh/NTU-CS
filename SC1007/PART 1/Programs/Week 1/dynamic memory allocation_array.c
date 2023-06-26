/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Write a program that asks the user how many integers will be entered, then asks for each integer.
Purpose: Dynamic Memory allocation for arrays. */
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>   // printf, scanf, NULL
#include <stdlib.h>  // malloc, free, rand

int main()
{
    int n;                                          // A variable to store the number of integers that the user is going to enter.
    int i;                                          // The index variable for "for loop".
    int *int_arr;                                   // Pointer to an integer

    printf("How many integers do you have? ");      // Print a question for the user to enter the number of integers.
    scanf("%d", &n);                                // Read the integer value that the user has entered for the number of integers.

    int_arr = malloc(n * sizeof(int));              // Reserve the requested memory (multiply the size of an integer by the number of integers user is going to enter)
                                                    // and sets the pointer  int_arr to point to the start of it.

    if (int_arr == NULL) printf("Uh oh.\n");        // The returned pointer should be NULL in case of failure.

    // Run "for loop" n times and store integers entered into the int_arr.
    for (i=0; i<n; i++){
        printf("Enter an integer: ");
        scanf("%d", &int_arr[i]);
    }

    return 0;
}
