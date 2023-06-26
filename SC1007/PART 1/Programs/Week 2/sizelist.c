////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Generate a list of M (10) numbers by inserting random numbers (0--99) into the front of the list until it has M (10) nodes, then remove all nodes. */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
	int item;
	struct _listnode *next;
}ListNode;

void printList(ListNode *head);
ListNode * findNode(ListNode *head, int index);
int insertNode(ListNode **ptrHead, int index, int value);
int removeNode(ListNode **ptrHead, int index);
int sizeList(ListNode *head);

int main()
{
	ListNode *head, **ptrHead;
	head = NULL;
	ptrHead = &head;

	srand(time(NULL));

	while (sizeList(head) < 10){
		insertNode(ptrHead, 0, rand() % 100);
		printf("The resulting list after inserting random numbers: ");
		printList(head);
		printf("\n");
	}
	printf("The size of the list is %d\n", sizeList(head));
	printf("\n");

	while (sizeList(head) > 0){
		removeNode(ptrHead, sizeList(head) - 1);
		printf("The resulting list after removing random numbers: ");
		printList(head);
		printf("\n");
	}
	printf("\n");
	printf("The size of the list is %d\n", sizeList(head));

}

int sizeList(ListNode *head){
	int count = 0;
	if (head == NULL){
		return 0;
	}
	while (head != NULL){
		count++;
		head = head->next;

	}
	return count;
}

void printList(ListNode *head){

	if (head == NULL)
		return;
	while (head != NULL){
		printf("%d ", head->item);
		head = head->next;
	}
	printf("\n");
}

ListNode * findNode(ListNode *head, int index){
	if (head == NULL || index < 0) return NULL;
	while (index > 0){
		head = head->next;
		if (head == NULL)
			return NULL;
		index--;
	}
	return head;
}

int insertNode(ListNode **ptrHead, int index, int value){

	ListNode *pre, *cur;

	// If empty list or inserting first node, need to update head pointer
	if (*ptrHead == NULL || index == 0){
		cur = *ptrHead;
		*ptrHead = malloc(sizeof(ListNode));
		(*ptrHead)->item = value;
		(*ptrHead)->next = cur;
		return 0;
	}

	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(*ptrHead, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		return 0;
	}

	return -1;
}

int removeNode(ListNode **ptrHead, int index){
	ListNode *pre, *cur;
	// Sanity check for empty list
	if (*ptrHead == NULL)
		return -1;
	// If removing first node, need to update head pointer
	if (index == 0){
		cur = *ptrHead;
		*ptrHead = cur->next;
		free(cur);
		return 0;
	}
	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(*ptrHead, index - 1)) != NULL){
		if (pre->next == NULL) return -1;
		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		return 0;
	}
	return -1;
}
