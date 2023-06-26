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

typedef struct _stack{
    LinkedList ll;
} Stack;

// PROTOTYPE DECLARATION ////////////////////////////////////////////////////////////

void printList(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

void push(Stack *s, int item);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);

/////////////////////////////////////////////////////////////////////////////////////


int main(){
    int i = 0;                      // Declare a variable to store the user's input.
    Stack s;                        // Static declaration of Stack s
    s.ll.head = NULL;               // Initialize the LinkedList's head in Stack s to null.
    s.ll.tail = NULL;               // Initialize the LinkedList's tail in Stack s to null.
    s.ll.size = 0;                  // Initialize the size of the LinkedList in Stack s to 0.

    printf("Enter a number (-1 to end): ");
    scanf("%d", &i);

    //Get the user's input and Push them into the Stack.
    while (i != -1){
        push(&s, i);
        printf("Enter a number (-1 to end): ");
        scanf("%d", &i);
    }

    /* Pop values from the stack and print it*/
    printf("Popping stack: ");
    while (!isEmptyStack(&s))
        printf("%d ", pop(&s));

    return 0;
}

////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////

void push(Stack *s, int item){
	insertNode(&(s->ll), 0, item);
}

int pop(Stack *s){
	int item;

	item = ((s->ll).head)->item;
	removeNode(&(s->ll), 0);
	return item;
}

int peek(Stack *s){
	return ((s->ll).head)->item;
}

int isEmptyStack(Stack *s){
	if ((s->ll).size == 0) return 1;
	return 0;
}

/////////////////////////////////////////////////////////////////////
