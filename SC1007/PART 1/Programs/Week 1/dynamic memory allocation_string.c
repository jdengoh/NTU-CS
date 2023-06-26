//////////////////////////////////////////////////////////////////////////////////////////
/* Write a program that asks the user how long the string will be entered, then asks for string.
/* Purpose: Dynamically allocate memory space for a string and get that string from user */

/////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>   // printf, scanf, NULL
#include <stdlib.h>  // malloc, free, rand

int main()
{
    int n;
    char *str;                              // char *str is pointer to char

    printf("How long is your string? ");
    scanf("%d", &n);                        // Read the integer value that the user has entered for the number of character(s).

    str = malloc(n+1);                      // Reserve the requested memory (sizeof(char) = 1) and returns a pointer to it.

    if (str == NULL) printf("Uh oh.\n");    // The returned pointer should be NULL in case of failure.

    printf("Enter your string: ");
    scanf("%s", str);                       // Read the string which entered by the user
    printf("Your string is: %s\n", str);    // Print the string
    return 0;
}
