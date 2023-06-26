#include <stdio.h>
#include <stdlib.h>

/* Structure declaration */
typedef struct _listnode{
    int item;                   // Define item as an int (Each listnode contains an item)
    struct _listnode * next;   // Pointer to next node
} ListNode;

int main()
{
    /* Statically create a ListNode */
    /* Note the use of . notation*/
    ListNode static_node;           // Declare a ListNode variable
    static_node.item = 50;          // Assign a item (50) in node
    static_node.next = NULL;        // Node does not  link to another node

    printf("Static_node value: %d", static_node.item);      // Print the value of the item.

    return 0;
}
