#include <stdio.h>
#include <stdlib.h>

/* Structure declaration */
typedef struct _listnode{
    int item;                       // Define item as an int
    struct _listnode * next;        // Pointer to the next node
} ListNode;

int main(){
    /* Dynamically create a ListNode, where it uses malloc() to allocate memory while the program is running. */
    /* Note the use of -> instead of . */
    ListNode *dy_node = malloc(sizeof(ListNode));           // Reserve the requested memory (sizeof(ListNode)) and returns a pointer to it
    dy_node->item = 50;                                     // Assign a item (50) into node
    dy_node->next = NULL;                                   // Node does not  link to another node

    printf("Dynamic_node value: %d", dy_node->item);        // Print the value of the item.

    return 0;
}
