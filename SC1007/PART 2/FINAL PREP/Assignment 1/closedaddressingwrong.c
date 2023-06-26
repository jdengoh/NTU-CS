#include <stdio.h>
#include <stdlib.h>

#define LOAD_FACTOR 3

typedef struct _listnode{
    int key;
    struct _listnode *next;
    struct _listnode *pre;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
} HashTableNode;

typedef struct _hashTable{
   int hSize;
   int nSize;
   HashTableNode *Table;
} HashTable;

int Hash(int key,int hSize);

ListNode* HashSearch(HashTable, int);
int HashInsert(HashTable *, int);
int HashDelete(HashTable *, int);

//In Practice, we will not do it
void HashPrint(HashTable);

int main()
{
    int opt;
    int size;

    int i;
    int key;

    //Create a HashTable
    HashTable Q1;

    printf("============= Hash Table ============\n");
    printf("|1. Create a hash table             |\n");
    printf("|2. Insert a key to the hash table  |\n");
    printf("|3. Search a key in the hash table  |\n");
    printf("|4. Delete a key from the hash table|\n");
    printf("|5. Print the hash table            |\n");
    printf("|6. Quit                            |\n");
    printf("=====================================\n");

    printf("Enter selection: ");
    scanf("%d",&opt);
    while(opt>=1 && opt <=5){
        switch(opt){
        case 1:
            printf("Enter number of data to be inserted:\n");
            scanf("%d",&size);

            Q1.hSize = (int)size/ LOAD_FACTOR;
            Q1.nSize = 0;

            Q1.Table = (HashTableNode *) malloc(sizeof(HashTableNode)*(Q1.hSize));

            for(i=0;i<Q1.hSize;i++){
                Q1.Table[i].head = NULL;
                Q1.Table[i].size = 0;
            }
            printf("HashTable is created.\n");
            break;
        case 2: //Insertion
            printf("Enter a key to be inserted:\n");
            scanf("%d",&key);
            if(HashInsert(&Q1,key))
                printf("%d is inserted.\n",key);
            else
                printf("%d is a duplicate. No key is inserted.\n",key);
            break;
        case 3: //Search
            printf("Enter a key for searching in the HashTable:\n");
            scanf("%d",&key);
            ListNode* node = HashSearch(Q1, key);

            if(node!=NULL)
                printf("%d is found.\n",key);
            else
                printf("%d is not found.\n",key);
            break;
        case 4: //Deletion
            printf("Enter a key to be deleted:\n");
            scanf("%d",&key);
            if(HashDelete(&Q1,key))
                printf("%d is deleted.\n",key);
            else
                printf("%d is not existing.\n",key);
            break;
        case 5:
            HashPrint(Q1);
            break;
        }

    printf("Enter selection: ");
    scanf("%d",&opt);
    }

    for(i=0;i<Q1.hSize;i++)
    {
        while(Q1.Table[i].head)
        {
            ListNode *temp;
            temp = Q1.Table[i].head;
            Q1.Table[i].head = Q1.Table[i].head->next;
            free(temp);
        }
    }
    free(Q1.Table);

    return 0;
}



int HashInsert(HashTable* Q1Ptr, int key)
{
    //Write your code here

    int hash = Hash(key, Q1Ptr->hSize);
    ListNode *temp;
    temp = NULL;

    if (HashSearch(*Q1Ptr, key) != NULL) return 0;

    temp = Q1Ptr->Table[hash].head;

    Q1Ptr->Table[hash].head = malloc(sizeof(ListNode));

    Q1Ptr->Table[hash].head->key = key;
    Q1Ptr->Table[hash].head->pre = NULL;

    if(temp!=NULL) {
        Q1Ptr->Table[hash].head->next = temp;
        temp -> pre = Q1Ptr->Table[hash].head;
    }
    else {
        Q1Ptr->Table[hash].head->next = NULL;
    }

    Q1Ptr->nSize++;
    Q1Ptr->Table[hash].size++;

    return 1;

}

int HashDelete(HashTable* Q1Ptr, int key)
{
    //Write your code here
    ListNode *temp, *pre, *next;
    temp = NULL;
    pre = NULL;
    next = NULL;

    int hash = Hash(key, Q1Ptr->hSize);

    temp = HashSearch(*Q1Ptr, key);

    if (temp == NULL) {
        return 0;
    }

    if (temp->pre != NULL) {
        pre = temp->pre;
    }

    if (temp->next != NULL) {
        next = temp->next;
    }

    if (pre == NULL) {
        if (next==NULL) Q1Ptr->Table[hash].head = NULL;

        else {
            Q1Ptr->Table[hash].head = next;
            next->pre = NULL;
        }
    }

    else {
        if (next==NULL) {
            pre->next = NULL;
        }
        else {
            pre->next = next;
            next->pre = pre;
        }
    }

    free(temp);
    Q1Ptr->Table[hash].size--;
    Q1Ptr->nSize--;

    return 1;

}

int Hash(int key,int hSize)
{
    return key%hSize;
}

ListNode* HashSearch(HashTable Q1, int key)
{
    int index;

    ListNode *temp;

    if(Q1.hSize != 0)
      index = Hash(key,Q1.hSize);
    else
      return NULL;

    temp = Q1.Table[index].head;
    while(temp !=NULL){
        if(temp->key == key)
            return temp;
        temp = temp->next;
    }

    return NULL;
}

void HashPrint(HashTable Q1)
{
    int i;
    ListNode *temp;
    for(i=0;i<Q1.hSize;i++)
    {
        temp =Q1.Table[i].head;
        printf("%d:  ",i);
        while(temp !=NULL)
        {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("\n");
    }
}
