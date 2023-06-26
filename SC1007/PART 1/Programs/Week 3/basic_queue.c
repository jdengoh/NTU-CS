#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
    int item;
    struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
    int size;
    ListNode *head;
    ListNode *tail;
} LinkedList;

typedef struct _queue{
     LinkedList ll;
} Queue;

// PROTOTYPE DECLARATION //////////////////////////////////////////////////////

void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int isEmptyQueue(Queue *s);

void printList(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

///////////////////////////////////////////////////////////////////////////////

int main()
{
    Queue q;                            // Declare a Queue structure.
    q.ll.head = NULL;                   // Initialize the LinkedList's head in Queue q to null.
    q.ll.tail = NULL;                   // Initialize the LinkedList's tail in Queue q to null.
    q.ll.size = 0;                      // Initialize the LinkedList's size in Queue q to 0.

    enqueue(&q, 1);                     // Enqueue an item with value 1 into the Queue.
    enqueue(&q, 2);                     // Enqueue an item with value 2 into the Queue.
    enqueue(&q, 3);                     // Enqueue an item with value 3 into the Queue.
    enqueue(&q, 4);                     // Enqueue an item with value 4 into the Queue.
    enqueue(&q, 5);                     // Enqueue an item with value 5 into the Queue.
    enqueue(&q, 6);                     // Enqueue an item with value 6 into the Queue.

    printf("Print the resulting queue: ");
    printList(&(q.ll));

    printf("\n Dequeue the queue: ");
    while (!isEmptyQueue(&q))           // Execute "while" loop when the queue is not empty/
        printf("%d ", dequeue(&q));     // Dequeue and print the item value.
    return 0;
}

/* Purpose: Enqueue an item into the queue.
   Parameters:
    - Queue *q  : Pointer q pointing to a Queue structure.
    - item      : Item to be added into the Queue. */
void enqueue(Queue *q, int item){
   insertNode(&(q->ll), q->ll.size, item);     // Call insertNode (LinkedList's function)
                                               // to insert an item at the end of the queue.
}

/* Purpose: Dequeue an item from the queue and return the dequeued item's value.
   Parameters:
    - Queue *q  : Pointer q pointing to a Queue structure.
*/
int dequeue(Queue *q){
   int item;                        // Declare a local variable 'item' to store the value of the dequeued item.
   item = ((q->ll).head)->item;     // Assign the item value of the LinkedList's first node to the local variable 'item'.
   removeNode(&(q->ll), 0);         // Remove the node from the LinkedList at index 0 (first node).
   return item;                     // Return the local variable 'item'.
}


/* Purpose: Peek at the value at the start (in front) of the queue.
   Parameters:
    - Queue *q  : Pointer q pointing to a Queue structure.
*/
int peek(Queue *q){
    return ((q->ll).head)->item;    // Return the item value of the node that is pointed by the head pointer (first node).
}


/* Purpose: Check if the queue is empty.
   Parameters:
    - Queue *q  : Pointer q pointing to a Queue structure.
*/
int isEmptyQueue(Queue *q){
   if ((q->ll).size == 0)           // Check the size property of the LinkedList.
      return 1;                     // If the size is 0, return 1 (true).
   return 0;                        // Else, return 0 (false).
}

/////////////////////////////////////////////////////////////////////////////////

void printList(LinkedList *ll){

    ListNode *temp = ll->head;

    if (temp == NULL)
        return;

    while (temp != NULL){
        printf("%d ", temp->item);
        temp = temp->next;
    }
}

//////////////////////////////////////////////////////////////////////////////////

ListNode * findNode(LinkedList *ll, int index){

    ListNode *temp;

    if (ll == NULL || index < 0 || index >= ll->size)
        return NULL;

    temp = ll->head;

    if (temp == NULL || index < 0)
        return NULL;

    while (index > 0){
        temp = temp->next;
        if (temp == NULL)
            return NULL;
        index--;
    }

    return temp;
}

///////////////////////////////////////////////////////////////////////

int insertNode(LinkedList *ll, int index, int value){

    ListNode *pre, *cur;

    if (ll == NULL || index < 0 || index > ll->size + 1)
        return -1;

    // If empty list or inserting first node, need to update head pointer
    if (ll->head == NULL || index == 0){
        cur = ll->head;
        ll->head = malloc(sizeof(ListNode));

        if (ll->size == 0)
            ll->tail = ll->head;

        ll->head->item = value;
        ll->head->next = cur;
        ll->size++;
        return 0;
    }

    // Inserting as new last node
    if (index == ll->size){
        pre = ll->tail;
        cur = pre->next;
        pre->next = malloc(sizeof(ListNode));
        ll->tail = pre->next;
        pre->next->item = value;
        pre->next->next = cur;
        ll->size++;
        return 0;
    }

    // Find the nodes before and at the target position
    // Create a new node and reconnect the links
    if ((pre = findNode(ll, index-1)) != NULL){
        cur = pre->next;
        pre->next = malloc(sizeof(ListNode));
        pre->next->item = value;
        pre->next->next = cur;
        ll->size++;
        return 0;
    }

    return -1;
}

/////////////////////////////////////////////////////////////////////////

int removeNode(LinkedList *ll, int index){

    ListNode *pre, *cur;

    // Highest index we can remove is size-1
    if (ll == NULL || index < 0 || index >= ll->size)
        return -1;

    // If removing first node, need to update head pointer
    if (index == 0){
        cur = ll->head->next;
        free(ll->head);
        ll->head = cur;
        ll->size--;

        if (ll->size == 0)
            ll->tail = 0;

        return 0;
    }

    // Find the nodes before and after the target position
    // Free the target node and reconnect the links
    if ((pre = findNode(ll, index-1)) != NULL){

        // Removing the last node, update the tail pointer
        if (index == ll->size - 1){
            ll->tail = pre;
            free(pre->next);
            pre->next = NULL;
        }
        else{
            cur = pre->next->next;
            free(pre->next);
            pre->next = cur;
        }
        ll->size--;
        return 0;
    }

    return -1;
}
