#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode {
    int vertex;
    struct _listnode *next;
} ListNode;

typedef struct _graph {
    int V;
    int E;
    ListNode **list;
} Graph;

typedef ListNode QueueNode;

typedef struct _queue {
    int size;
    QueueNode *head;
    QueueNode *tail;
} Queue;

int BFS(Graph G, int v, int w);

void printGraphList(Graph);

// You should not change the prototypes of these functions
void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void removeAllItemsFromQueue(Queue *qPtr);

int main() {
    Graph g;
    int i, j;
    ListNode *temp;

    printf("Enter the number of vertices:\n");
    scanf("%d", &g.V);

    g.list = (ListNode **)malloc(g.V * sizeof(ListNode *));

    for (i = 0; i < g.V; i++)
        g.list[i] = NULL;

    printf("Enter two vertices which are adjacent to each other:\n");
    while (scanf("%d %d", &i, &j) == 2) {
        i = i - 1;

        if (g.list[i] == NULL) {
            g.list[i] = (ListNode *)malloc(sizeof(ListNode));
            g.list[i]->vertex = j;
            g.list[i]->next = NULL;
        } else {
            temp = (ListNode *)malloc(sizeof(ListNode));
            temp->next = g.list[i];
            temp->vertex = j;
            g.list[i] = temp;
        }
        g.E++;
        printf("Enter two vertices which are adjacent to each other:\n");
    }
    scanf("%*c");
    printf("Enter two vertices for finding their shortest distance:\n");
    scanf("%d %d", &i, &j);

    int d = BFS(g, i, j);

    if (d == -1)
        printf("%d and %d are unconnected.\n", i, j);
    else
        printf("The shortest distance is %d\n", d);
    printGraphList(g);
    return 0;
}

int BFS(Graph g, int v, int w) {
    if (!g.V || v > g.V || w > g.V) return -1;
    Queue *q = malloc(sizeof(Queue));
    ListNode *n = NULL;
    int explored[g.V], i, cur, dist = 0;
    for (i = 0; i < g.V; i++)
        explored[i] = -1;
    // no parent and start node
    explored[v - 1] = 0;
    q->head = q->tail = NULL;
    q->size = 0;
    enqueue(q, v);

    while (!isEmptyQueue(*q)) {
        cur = getFront(*q);
        dequeue(q);
        if (cur == w) break;
        n = g.list[cur - 1];
        while (n) {
            // Check if not explored
            if (explored[n->vertex - 1] == -1) {
                enqueue(q, n->vertex);
                // link child to parent
                explored[n->vertex - 1] = cur;
            }
            n = n->next;
        }
    }
    // If node exists backtrack
    if (explored[w - 1] != -1) {
        i = explored[w - 1];

        while (i != 0) {
            i = explored[i - 1];
            dist++;
        }
    } else {
        dist = explored[w - 1];
    }

    removeAllItemsFromQueue(q);
    free(q);
    return dist;
}

void printGraphList(Graph g) {
    int i;
    ListNode *temp;

    for (i = 0; i < g.V; i++) {
        printf("%d:\t", i + 1);
        temp = g.list[i];
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void enqueue(Queue *qPtr, int item) {
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    if (newNode == NULL) exit(0);

    newNode->vertex = item;
    newNode->next = NULL;

    if (isEmptyQueue(*qPtr))
        qPtr->head = newNode;
    else
        qPtr->tail->next = newNode;

    qPtr->tail = newNode;
    qPtr->size++;
}

int dequeue(Queue *qPtr) {
    if (qPtr == NULL || qPtr->head == NULL) {  //Queue is empty or NULL pointer
        return 0;
    } else {
        QueueNode *temp = qPtr->head;
        qPtr->head = qPtr->head->next;
        if (qPtr->head == NULL)  //Queue is emptied
            qPtr->tail = NULL;

        free(temp);
        qPtr->size--;
        return 1;
    }
}

int getFront(Queue q) {
    return q.head->vertex;
}

int isEmptyQueue(Queue q) {
    if (q.size == 0)
        return 1;
    else
        return 0;
}

void removeAllItemsFromQueue(Queue *qPtr) {
    while (dequeue(qPtr))
        ;
}
