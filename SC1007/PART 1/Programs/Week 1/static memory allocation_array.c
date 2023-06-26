/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Write a program that asks the user how many integers will be entered, then asks for each integer.
Purpose: Define a fixed size array, ask the user the number of integers he/she wish to enter and store each integer in the defined array. */

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>                      // printf, scanf, NULL
#define MY_FAVORITE_BIG_NUMBER 100      // Define a constant variable with value of 100


int main()
{
    int numOfNumbers;                                           // A variable to store the number of integers that the user is going to enter.
    int i;                                                      // A variable to use as the index for "for loop"
	int numArray[MY_FAVORITE_BIG_NUMBER];                       // Declare a static array, numArray, of 100 ints

    printf("How many integer(s) will be entered? ");
    scanf("%d", &numOfNumbers);                                 // Read the integer value that the user has entered for the number of integers.

/* Run "for loop" numOfNumbers times and store entered integers into the numArray. */
    for (i=0; i<numOfNumbers; i++){
        printf("Enter an integer: ");
        scanf("%d", &numArray[i]);                              // &numArray[i] : Address of numArray of index i.
        printf("Print entered numbers: %d\n", numArray[i]);     // Print the entered numbers
    }

    return 0; //The return value of the main function is considered the "Exit Status" of the application. On most operating systems returning 0 is a success status like saying "The program worked fine".
}
