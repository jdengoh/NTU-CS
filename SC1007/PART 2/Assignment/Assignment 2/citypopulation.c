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
    ListNode **list;
}Graph;

typedef ListNode QueueNode;

typedef struct _queue{
   int size;
   QueueNode *head;
   QueueNode *tail;
} Queue;

int isEmptyQueue(Queue q) {
    if(q.size==0) return 1;
    else return 0;
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

void removeAllItemsFromQueue(Queue *qPtr)
{
	while(dequeue(qPtr));
}

int* city_population (int N, int* population, int** road, int Q, int** cities)
{
    int *visited;
    int *answer;
    int start,end, index;
    visited = (int *)malloc(N*sizeof(int));
    answer = (int *)malloc(Q*sizeof(int));

    Queue q;

    for (int i=0; i<N; i++) {
        visited[i] = 0;
    }

    for(int j=0; j<Q; j++) {
        answer[j] = 0;
    }

    int city, cond = 0;

    ListNode *cur, *ptr, **list;

    list = (ListNode **) malloc(N * sizeof(ListNode *));

    for (int i=0; i<N; i++) {
        list[i] = NULL;
    }

    //convert to adj list;

    for (int i=0; i<N-1; i++) {

        if (list[ (road[i][0])-1 ] == NULL) {

            list[ (road[i][0])-1 ] = (ListNode *)malloc(sizeof(ListNode));
            list[ (road[i][0])-1 ] -> vertex = road[i][1];
            list[ (road[i][0])-1 ] -> next = NULL;

        }

        else {
            cur = list[ (road[i][0])-1 ];
            while (cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = (ListNode *)malloc(sizeof(ListNode));
            cur->next->vertex = road[i][1];
            cur->next->next = NULL;
        }

        if (list[ (road[i][1])-1 ] == NULL) {

            list[ (road[i][1])-1 ] = (ListNode *)malloc(sizeof(ListNode));
            list[ (road[i][1])-1 ] -> vertex = road[i][0];
            list[ (road[i][1])-1 ] -> next = NULL;

        }

        else {
            cur = list[ (road[i][1])-1 ];
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
        visited[start-1] = -1;

        while(!isEmptyQueue(q)) {

            city = getFront(q);
            dequeue(&q);

            ptr = list[city-1];

            while(ptr!=NULL) {

                if(visited[(ptr->vertex)-1] == 0) {
                    enqueue (&q, ptr->vertex);
                    visited[(ptr->vertex)-1] = city;
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

        printf("found a path for run %d\n", i_q);

        while(city!=start) {

            if(population[city-1] <= cities[i_q][2]) {
                answer[i_q]++;
            }

            city = visited[city-1];

        }

        if(population[start-1] <= cities[i_q][2]) {
            answer[i_q]++;
        }

        removeAllItemsFromQueue(&q);
        for (int i=0; i<N; i++) {
            visited[i] = 0;
        }
        //printf("next run?");

        printf("answer:");
        for(int i_out_ = 0; i_out_ < Q; i_out_++)
            printf("\n%d", answer[i_out_]);
        printf("\n");


    }

    return answer;
}

