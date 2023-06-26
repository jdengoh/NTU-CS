#include<stdio.h>
#include <stdlib.h>

int* city_population (int N, int* population, int** road, int Q, int** cities) ;

int main() {
    int N;
    scanf("%d", &N);
    int i_population;
    int *population = (int *)malloc(sizeof(int)*(N));
    for(i_population = 0; i_population < N; i_population++)
    	scanf("%d", &population[i_population]);
    int i_road, j_road;
    int **road = (int **)malloc((N-1)*sizeof(int *));
    for(i_road = 0; i_road < N-1; i_road++)
    {
    	road[i_road] = (int *)malloc((2)*sizeof(int));
    }
    for(i_road = 0; i_road < N-1; i_road++)
    {
    	for(j_road = 0; j_road < 2; j_road++)
    	{
    		scanf("%d", &road[i_road][j_road]);
    	}
    }
    int Q;
    scanf("%d", &Q);
    int i_cities, j_cities;
    int **cities = (int **)malloc((Q)*sizeof(int *));
    for(i_cities = 0; i_cities < Q; i_cities++)
    {
    	cities[i_cities] = (int *)malloc((3)*sizeof(int));
    }
    for(i_cities = 0; i_cities < Q; i_cities++)
    {
    	for(j_cities = 0; j_cities < 3; j_cities++)
    	{
    		scanf("%d", &cities[i_cities][j_cities]);
    	}
    }

    int* out_ = city_population(N, population, road, Q, cities);
    printf("%d", out_[0]);
    int i_out_;
    for(i_out_ = 1; i_out_ < Q; i_out_++)
    	printf("\n%d", out_[i_out_]);
}

typedef struct _listnode
{
    int vertex;
	struct _listnode *next;
} ListNode;

typedef struct _graph{
    int V;
    int E;
    int *visited;
    ListNode **list;
}Graph;

typedef ListNode QueueNode;

typedef struct _queue{
   int size;
   QueueNode *head;
   QueueNode *tail;
} Queue;

void enqueue(Queue *qPtr, int item);
int dequeue(Queue *qPtr);
int getFront(Queue q);
int isEmptyQueue(Queue q);
void removeAllItemsFromQueue(Queue *qPtr);

void enqueue(Queue *qPtr, int item) {
    QueueNode *newNode;
    newNode = malloc( sizeof(QueueNode));
    if(newNode==NULL) exit(0);

    newNode->vertex = item;
    newNode->next = NULL;

    if(isEmptyQueue(*qPtr))
        qPtr->head=newNode;
    else
        qPtr->tail->next = newNode;

    qPtr->tail = newNode;
    qPtr->size++;
}

int dequeue(Queue *qPtr) {
    int num;
    if(qPtr==NULL || qPtr->head==NULL){ //Queue is empty or NULL pointer
        return 0;
    }
    else{
       QueueNode *temp = qPtr->head;
       qPtr->head = qPtr->head->next;
       if(qPtr->head == NULL) //Queue is emptied
           qPtr->tail = NULL;
        num = temp->vertex;
       free(temp);
       qPtr->size--;
       return num;
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

int* city_population (int N, int* population, int** road, int Q, int** cities)
{
    int *answer;
    int start,end, index;
    Graph g;

    g.V = N;
    g.E = N-1;
    g.visited = (int *)malloc(g.V * sizeof(int));
    g.list = (ListNode **) malloc(g.V * sizeof(ListNode *));

    for (int i=0; i<g.V; i++) {
        g.list[i] = NULL;
        g.visited[i] = 0;
     }

    answer = (int *)malloc(Q*sizeof(int));

    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;

    for(int j=0; j<Q; j++) {
        answer[j] = 0;
    }

    int city, cond = 0;

    ListNode *cur, *ptr;

    //convert to adj list;

    for (int i=0; i<N-1; i++) {

        if (g.list[ (road[i][0])-1 ] == NULL) {

            g.list[ (road[i][0])-1 ] = (ListNode *)malloc(sizeof(ListNode));
            g.list[ (road[i][0])-1 ] -> vertex = road[i][1];
            g.list[ (road[i][0])-1 ] -> next = NULL;

        }

        else {
            cur = g.list[ (road[i][0])-1 ];
            while (cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = (ListNode *)malloc(sizeof(ListNode));
            cur->next->vertex = road[i][1];
            cur->next->next = NULL;
        }

        if (g.list[ (road[i][1])-1 ] == NULL) {

            g.list[ (road[i][1])-1 ] = (ListNode *)malloc(sizeof(ListNode));
            g.list[ (road[i][1])-1 ] -> vertex = road[i][0];
            g.list[ (road[i][1])-1 ] -> next = NULL;

        }

        else {
            cur = g.list[ (road[i][1])-1 ];
            while (cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = (ListNode *)malloc(sizeof(ListNode));
            cur->next->vertex = road[i][0];
            cur->next->next = NULL;
        }

    }

    //printf("adj created succesfully");


    for(int i_q=0; i_q<Q; i_q++) {

        cond =0;
        start = cities[i_q][0];
        end = cities[i_q][1];

        enqueue(&q, start);
        g.visited[start-1] = -1;

        while(!isEmptyQueue(q)) {


            city = dequeue(&q);

            ptr = g.list[city-1];

            while(ptr!=NULL) {

                if(g.visited[(ptr->vertex)-1] == 0) {
                    enqueue (&q, ptr->vertex);
                    g.visited[(ptr->vertex)-1] = city;
                }

                if(ptr->vertex == end) {
                    cond = 1;
                    break;
                }

                ptr = ptr->next;

            }

            if(cond==1) break;

        }

        city = end;

        //printf("found a path for run %d\n", i_q);

        while(city!=-1) {

            if(population[city-1] <= cities[i_q][2]) {
                answer[i_q]++;
            }

            city = g.visited[city-1];

        }


        removeAllItemsFromQueue(&q);
        for (int i=0; i<N; i++) {
            g.visited[i] = 0;
        }
        //printf("next run?");


    }

    return answer;

}
