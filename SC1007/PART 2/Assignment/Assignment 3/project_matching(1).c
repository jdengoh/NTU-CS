#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
 int vertex;
 struct _listnode *next;
} ListNode;
typedef ListNode StackNode;

typedef struct _graph{
 int V;
 int E;
 ListNode **list;
}Graph;

typedef ListNode QueueNode;

typedef struct _queue{
 int size;
 QueueNode *head;
 QueueNode *tail;
} Queue;

typedef struct _stack
{
 int size;
 StackNode *head;
} Stack;

void insertAdjVertex(ListNode** AdjList,int vertex);
void removeAdjVertex(ListNode** AdjList,int vertex);
int matching(Graph g);

void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void removeAllItemsFromQueue(Queue *qPtr);
void printQ(QueueNode *cur);
//////STACK///////////////////////////////////////////
void push(Stack *sPtr, int vertex);
int pop(Stack *sPtr);
int peek(Stack s);
int isEmptyStack(Stack s);
void removeAllItemsFromStack(Stack *sPtr);
//////////////////////////////////

int main()
{
 int Prj, Std, Mtr; //Project, Student and Mentor;
 int maxMatch;
 scanf("%d %d %d", &Std, &Prj, &Mtr);

 int np,nm; //number of projects and number of mentors

 int vert;
 int prjno, mentno;

 //build graph
 Graph g;

 vert = Prj+Std+Std+Mtr+2;  //plus 2 for source and sink
 g.V = vert;
 g.list = (ListNode **)malloc(g.V*sizeof(ListNode *));

 //initialize graph
 for(int i=0; i<g.V; i++) {
    g.list[i] = NULL;
 }

 //source to proj

 for (int i = 0; i<Prj; i++) {
    insertAdjVertex(&g.list[g.V-2], i+1);
    g.E++;
 }

 //std to std
 for (int i = Prj; i< Prj+Std ; i++) {
    insertAdjVertex(&g.list[i], i+Std+1);
    g.E++;
 }

 //mentor to sink
 for (int i=Prj+Std+Std; i<g.V-2; i++) {
    insertAdjVertex(&g.list[i], g.V);
    g.E++;
 }

 //edges for each student
 for (int i=0; i<Std; i++) {

    //np, nm
    scanf("%d %d", &np, &nm);

    //proj to stud
    for (int j=0; j<np; j++) {
        scanf("%d", &prjno);
        insertAdjVertex(&g.list[prjno - 1], (Prj+1)+i);
        g.E++;
    }

    // stud to mentor
    for (int k=0; k<nm; k++) {
        scanf("%d", &mentno);
        insertAdjVertex(&g.list[Prj+Std+i], ((Prj+Std+Std) + mentno));
        g.E++;
    }
 }

 //apply Ford Fulkerson algorithm
 // use DFS or BFS to find a path
 maxMatch = matching(g);
 printf("%d\n", maxMatch);
 return 0;
}

int matching(Graph g)
{

 //Write your code
 int **flow, **residual, *visited;
 ListNode *ptr;
 int flow_cond;
 Queue q;
 q.head = NULL;
 q.tail = NULL;
 q.size = 0;

 visited = (int *)malloc(g.V*sizeof(int));
 residual = (int **)malloc(g.V*sizeof(int *));
 flow = (int **)malloc(g.V*sizeof(int *));

 //initialize
 for(int i=0; i<g.V; i++) {
    flow[i] = (int *)malloc(g.V*sizeof(int));
 }

 for(int i=0; i<g.V; i++) {
    visited[i]=-1;

    for (int j=0; j<g.V; j++) {
        flow[i][j] = 0;
    }
 }

     for (int i=0; i<g.V; i++) {

        ptr = g.list[i];

        while (ptr!=NULL) {
            flow[i][ptr->vertex -1] = 1;
            ptr = ptr->next;
        }
     }

 int start = g.V-2;
 int end = g.V-1;
 int num;
 int index, parent;
 ListNode *temp;

 while(1) {

    flow_cond = 0;
    enqueue(&q, start);

    while(!isEmptyQueue(q)) {
        num = getFront(q);
        dequeue(&q);

        if (num == end) {
            flow_cond = 1;
            break;
        }

        temp = g.list[num-1];

        while (temp!=NULL) {

            if( visited[(temp->vertex-1)] == -1) {
                enqueue(&q, temp->vertex);
                visited[(temp->vertex-1)] = num;
            }
            temp = temp->next;
        }
    }

    removeAllItemsFromQueue(&q);

    if (flow_cond == 0) break; //no more new flow
    else flow_cond = 1;

    index = end;

    while (index!=start) {
        parent = visited[index-1];

        if (flow[index-1][parent-1] != 0) {
            flow[index-1][parent-1]--;
        }
        else {
            flow[parent-1][index-1]++;
        }

        removeAdjVertex(&g.list[parent-1], index);
        insertAdjVertex(&g.list[index-1], parent);
        index = parent;

    }

 }
 int count;
 int j;
 for (int i=0; i<g.V; i++) {
    if (flow[start-1][i] == 0) continue;
    index = i+1;
    j = 0;

    while(j < g.V) {
        if (flow[index-1][j] == 0) continue;
        if (j == end) {
            count++;
            break;
        }
        index = j;
        j = 0;
    }
 }

 return count;

}

void removeAdjVertex(ListNode** AdjList,int vertex)
{
 ListNode *temp, *preTemp;
 if(*AdjList != NULL)
 {
    if((*AdjList)->vertex ==vertex){//first node
      temp = *AdjList;
      *AdjList = (*AdjList)->next;
      free(temp);
      return;
    }
    preTemp = *AdjList;
    temp = (*AdjList)->next;
    while(temp!=NULL && temp->vertex != vertex)
    {
      preTemp= temp;
      temp = temp->next;
    }
    preTemp->next = temp->next;
    free(temp);
   }
}

void insertAdjVertex(ListNode** AdjList,int vertex)
{
  ListNode *temp;
  if(*AdjList==NULL)
  {
     *AdjList = (ListNode *)malloc(sizeof(ListNode));
     (*AdjList)->vertex = vertex;
     (*AdjList)->next = NULL;
  }
  else{
     temp = (ListNode *)malloc(sizeof(ListNode));
     temp->vertex = vertex;
     temp->next = *AdjList;
     *AdjList = temp;
  }
}

void enqueue(Queue *qPtr, int vertex) {
  QueueNode *newNode;
  newNode = malloc(sizeof(QueueNode));
  if(newNode==NULL) exit(0);

  newNode->vertex = vertex;
  newNode->next = NULL;

  if(isEmptyQueue(*qPtr))
     qPtr->head=newNode;
  else
     qPtr->tail->next = newNode;

     qPtr->tail = newNode;
     qPtr->size++;
}

int dequeue(Queue *qPtr) {
   if(qPtr==NULL || qPtr->head==NULL){ //Queue is empty or NULL pointer
     return 0;
   }
   else{
     QueueNode *temp = qPtr->head;
     qPtr->head = qPtr->head->next;
     if(qPtr->head == NULL) //Queue is emptied
       qPtr->tail = NULL;

     free(temp);
     qPtr->size--;
     return 1;
}
}

int getFront(Queue q){
    return q.head->vertex;
}

int isEmptyQueue(Queue q) {
   if(q.size==0) return 1;
   else return 0;
}

void removeAllItemsFromQueue(Queue *qPtr)
{
  while(dequeue(qPtr));
}

void printQ(QueueNode *cur){
 if(cur==NULL) printf("Empty");

 while (cur != NULL){
    printf("%d ", cur->vertex);
    cur = cur->next;
  }
 printf("\n");
}

void push(Stack *sPtr, int vertex)
{
  StackNode *newNode;
  newNode= malloc(sizeof(StackNode));
  newNode->vertex = vertex;
  newNode->next = sPtr->head;
  sPtr->head = newNode;
  sPtr->size++;
}

int pop(Stack *sPtr)
{
  if(sPtr==NULL || sPtr->head==NULL){
     return 0;
  }
  else{
     StackNode *temp = sPtr->head;
     sPtr->head = sPtr->head->next;
     free(temp);
     sPtr->size--;
     return 1;
   }
}

int isEmptyStack(Stack s)
{
    if(s.size==0) return 1;
    else return 0;
}

int peek(Stack s){
   return s.head->vertex;
}

void removeAllItemsFromStack(Stack *sPtr)
{
   while(pop(sPtr));
}
