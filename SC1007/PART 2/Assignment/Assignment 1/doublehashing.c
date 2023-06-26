#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 37
#define PRIME     13

enum Marker {EMPTY,USED,DELETED};

typedef struct _slot{
    int key;
    enum Marker indicator;
} HashSlot;

int HashInsert(int key, HashSlot hashTable[]);
int HashDelete(int key, HashSlot hashTable[]);


int hash1(int key);
int hash2(int key);

int main()
{
    int opt;
    int i;
    int key;
    int comparison;
    HashSlot hashTable[TABLESIZE];

    for(i=0;i<TABLESIZE;i++){
        hashTable[i].indicator = EMPTY;
        hashTable[i].key = 0;
    }

    printf("============= Hash Table ============\n");
    printf("|1. Insert a key to the hash table  |\n");
    printf("|2. Delete a key from the hash table|\n");
    printf("|3. Print the hash table            |\n");
    printf("|4. Quit                            |\n");
    printf("=====================================\n");
    printf("Enter selection: ");
    scanf("%d",&opt);
    while(opt>=1 && opt <=3){
        switch(opt){
        case 1:
            printf("Enter a key to be inserted:\n");
            scanf("%d",&key);
            comparison = HashInsert(key,hashTable);
            if(comparison <0)
                printf("Duplicate key\n");
            else if(comparison < TABLESIZE)
                printf("Insert: %d Key Comparisons: %d\n",key, comparison);
            else
                printf("Key Comparisons: %d. Table is full.\n",comparison);
            break;
        case 2:
            printf("Enter a key to be deleted:\n");
            scanf("%d",&key);
            comparison = HashDelete(key,hashTable);
            if(comparison <0)
                printf("%d does not exist.\n", key);
            else if(comparison <= TABLESIZE)
                printf("Delete: %d Key Comparisons: %d\n",key, comparison);
            else
                printf("Error\n");
            break;
        case 3:
            for(i=0;i<TABLESIZE;i++) printf("%d: %d %c\n",i, hashTable[i].key,hashTable[i].indicator==DELETED?'*':' ');
            break;
        }
        printf("Enter selection: ");
        scanf("%d",&opt);
    }
    return 0;
}

int hash1(int key)
{
    return (key % TABLESIZE);
}

int hash2(int key)
{
    return (key % PRIME) + 1;
}

int HashInsert(int key, HashSlot hashTable[])
{
   //Write your code here

   int i, first_del = 50, del_ind;
   int count = 0;

   i = hash1(key);

   if (hashTable[i].indicator == EMPTY) {
    hashTable[i].key = key;
    hashTable[i].indicator = USED;
    return 0;

   }

   else {

    do {

        if (hashTable[i].indicator == USED) {

            if (hashTable[i].key == key)
                return -1;

            else {
                count++;
                i = hash1(key + count*hash2(key));
                continue;
            }
        }

        else if (hashTable[i].indicator == DELETED) {

            if (first_del == 50) {
                first_del = i;
                del_ind = count;
            }

            count++;
            i = hash1(key + count*hash2(key));
            continue;
        }

        else if (hashTable[i].indicator == EMPTY) {

            if (first_del==50){

                hashTable[i].key = key;
                hashTable[i].indicator = USED;

                return count;

            }

            else break;
        }

    } while (count!=37);


   if (first_del!=50) {
        hashTable[first_del].key = key;
        hashTable[first_del].indicator = USED;
        return del_ind;
   }

    return 37;

   }

}

int HashDelete(int key, HashSlot hashTable[])
{
   //Write your code here
   int i, count = 0;

   i = hash1(key);

   if (hashTable[i].indicator == EMPTY)
    return -1;

   else if (hashTable[i].key == key) {
    hashTable[i].indicator = DELETED;
    return 0;
   }

   else {

    while ( count!=37 && (hashTable[i].indicator != EMPTY) ) {

        if (hashTable[i].key == key && hashTable[i].indicator != DELETED) {
            hashTable[i].indicator = DELETED;
            return count;
        }

        else
            i = hash1(key + count*hash2(key));

        count++;

    }

    return -1;

   }

}
