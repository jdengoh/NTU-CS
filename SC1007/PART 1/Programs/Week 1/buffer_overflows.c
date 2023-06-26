/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* A buffer, in terms of a program in execution, can be thought of as a region of computer’s main memory that has certain
boundaries in context with the program variable that references this memory. A buffer is said to be overflown when the data
(meant to be written into memory buffer) gets written past the left or the right boundary of the buffer.
This way the data gets written to a portion of memory which does not belong to the program variable that references the buffer. */

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;                              // Declare the index variable for "for loop"
    int *arr

    arr = malloc(5 * sizeof(int));      // Reserve the requested memory (5 * sizeof(int)) and returns a pointer to it
    arr[i] = i;

    /* Note: Output will have an error when the allocated memory is not big enough to store the integers */
    for (i=0; i<10; i++)
        printf("%d ", arr[i]);

    return 0;
}
