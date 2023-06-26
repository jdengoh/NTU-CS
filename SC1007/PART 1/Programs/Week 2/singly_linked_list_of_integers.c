/////////////////////////////////////////////////////////////////////////////////////////

/* Purpose: Get user's integer input and store it in linked list until user enters -1 */

/////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

/* Define a new type definition */
typedef struct node{
    int item;                   // Each Listnode contains an integer value
    struct node *next;          // pointer to the next node
} ListNode;


int main(){
    ListNode *head, *temp;                   // Declare the head pointer and the temporary pointer.
    head = NULL;                            // Initially there are no nodes hence head=NULL
    int i = 0;

    printf("Enter an integer to store into linked list (-1 to end): ");
    scanf("%d", &i);
    while (i != -1){
        if (head == NULL){                          // If head=NULL...
            head = malloc(sizeof(ListNode));        // Allocated memory for the first node and update the head pointer.
            temp = head;                            // Update the temp with the value of head pointer. Then temp is also pointing to the first node
        }
        else{                                       // Second case, if the head is not null.
            temp->next = malloc(sizeof(ListNode));  // Allocated the memory for the new node and returned the address of it. Then update the next pointer of the previously created node with the returned address.
            temp = temp->next;                      // Advanced the temp pointer (that means temp is pointing to the current last node)
        }
        temp->item = i;                             // Store the input as the item of the current node
        printf("Enter an integer to store into linked list (-1 to end): ");
        scanf("%d", &i);
    }                                               // Go back to while loop.

    temp->next = NULL;                              // Store Last node's next pointer as NULL.

    return 0;
}
