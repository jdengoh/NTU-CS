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

typedef struct _v{
    int size, depth, parent, *get;
} vertex;

typedef struct _vec{
    int size, *get;
} vector;

int head[200001], heavy[200001], total[200001], pos[200001], B[200001], curpos=0, m;
vector *T[200001];

int get(int a, int b) { return m*a + b; }

void printVec(vector v) {
    for (int i=0;i<v.size;i++) printf("%d ", v.get[i]);
    printf("(Size %d)\n", v.size);
}

int dfs(int v,  vertex *adj) {
    int p = adj[v].parent, max = -1;
    total[v] = 1;
    heavy[v] = -1;
    for (int i=0;i<adj[v].size;i++) {
        int j = adj[v].get[i];
        if (j==p) continue;
        adj[j].depth = adj[v].depth+1;
        adj[j].parent = v;
        dfs(j, adj);
        if (total[j] > max) max=total[j], heavy[v]=j;
    }
    return total[v];
}

int *merge(vector v1, vector v2) {
    printf("Merging:\n");
    printVec(v1); printVec(v2);
    int i=0, j=0, n = v1.size + v2.size;
    int *res = malloc(sizeof(int)*(n)), *p = res;
    while (i<v1.size && j<v2.size)
        *p++ = v1.get[i]<v2.get[j]? v1.get[i++]:v2.get[j++];
    while (i<v1.size) *p++ = v1.get[i++];
    while (j<v2.size) *p++ = v2.get[j++];
    return res;
}

int buildTree(int *arr, vector st[], int p, int l, int r) {
    printf("getting %d to %d\n", l, r);
    if (l==r) {
        st[p].get = malloc(sizeof(int));
        st[p].get[0] = arr[l];
        printf("(%d value %d at %d)\n", l, arr[l], p);
        return st[p].size = 1;;
    }

    int mid = (l+r)>>1, a, b;
    a = buildTree(arr, st, p<<1, l, mid);
    b = buildTree(arr, st, (p<<1)+1, mid+1, r);
    printf("merging %d and %d\n", p<<1, p*2+1);
    st[p].get = merge(st[p<<1], st[(p<<1)+1]);
    st[p].size = a+b;
    printf("(%d, %d at %d): ", l, r, p);
    printVec(st[p]);
    return st[p].size = a+b;
}

int lower_bound(int *arr, int l, int r, int v) {
    printf("binsearch: ");
    for (int i=0;i<r;i++) printf("%d ", arr[i]);
    printf("\n");
    while (l<r) {
        int mid = (l+r)>>1;
        if (arr[mid]<=v) l = mid+1;
        else r = mid;
    }
    return r;
}

int check(vector *st, int p, int l, int r, int a, int b, int k) {
    if (l>b || r<a) return 0;
    printf("Checking %d to %d (%d, %d) %d\n", l, r, a, b, p);
    printVec(st[p]);
    if (a<=l && b>=r)
        return lower_bound(st[p].get, 0, st[p].size, k);
    int mid = (l+r)>>1;
    return check(st, p*2, l, mid, a, b, k) +
           check(st, p*2+1, mid+1, r, a, b, k);
}

int query(int a, int b, vertex *adj, int k) {
    int res = 0;
    for (;head[a] != head[b]; b=adj[b].parent) {
        if (adj[head[a]].depth > adj[head[b]].depth) {
            int t = a;
            a = b;
            b = t;
        }
        printf("1. for %d, querying %d from %d to %d\n", b, B[b], 0, pos[b]);
        res += check(T[B[b]], 1, 0, T[B[b]][1].size-1, 0, pos[b], k);
        printf("got %d\n", res);
    }
    if (adj[a].depth > adj[b].depth) {
        int t = a;
        a = b;
        b = t;
    }
    printf("2. querying %d from %d to %d\n", B[b], pos[a], pos[b]);
    res += check(T[B[b]], 1, 0, T[B[b]][1].size-1, pos[a], pos[b], k);
    printf("got %d\n", res);
    return res;
}

int lca(int a, int b, int *BL, vertex *adj) {
    if (adj[a].depth < adj[b].depth) {
        int t = a; a = b; b = t; }
    for (int i = m; i--;)
        if (adj[a].depth==adj[b].depth) break;
        else if (adj[a].depth - (1<<i) >= adj[b].depth)
            a = BL[get(a, i)];

    if (a==b) return a;
    for (int i=m; i--;)
        if (BL[get(a, i)] != BL[get(b, i)])
            a = BL[get(a, i)], b = BL[get(b, i)];

    return BL[get(a, 0)];
}

int decompose(int v, int h, vertex *adj, int *pop, int arr[], int c) {
    head[v] = h; arr[pos[v] = curpos++] = pop[v-1];
    B[v] = c;
    if (heavy[v] == -1) {
        T[c] = (vector*) malloc(sizeof(vector) * (curpos * 4 + 1));
        printf("Building Tree: ");
        for (int i=0;i<curpos;i++) printf("%d ", arr[i]);
        printf("\n");
        buildTree(arr, T[c], 1, 0, curpos-1);
        return c;
    }
    else c = decompose(heavy[v], h, adj, pop, arr, c);
    for (int i=0;i<adj[v].size;i++) {
        int j = adj[v].get[i];
        curpos = 0;
        if (j != adj[v].parent && j != heavy[v])
            c = decompose(j, j, adj, pop, malloc(sizeof(int)*total[j]), c+1);
    }
    return c;
}

int* city_population (int N, int* population, int** road, int Q, int** cities)
{
    vertex *adj = (vertex*) calloc(N+1, sizeof(vertex));
    int *e = (int*) calloc(N+1, sizeof(int));
    for (int i=0;i<N-1;i++) {
        e[road[i][0]]++;
        e[road[i][1]]++;
    }

    for (int i=0;i<N-1;i++) {
        int a = road[i][0], b = road[i][1];
        if (!adj[a].size) adj[a].get = (int*) malloc(sizeof(int)*e[a]);
        if (!adj[b].size) adj[b].get = (int*) malloc(sizeof(int)*e[b]);

        adj[a].get[adj[a].size++] = b;
        adj[b].get[adj[b].size++] = a;
    }

    dfs(1, adj);

    // Build decomposition tree
    int c = decompose(1, 1, adj, population, malloc(sizeof(int) * total[1]), 0);
    printf("c>>>>%d\n", c);

    for (int i=1;i<=N;i++) {
        printf("%d (%d): ", i, B[i]);
        for (int j=0;j<adj[i].size;j++) printf("%d ", adj[i].get[j]);
        printf("\n");
    }

    for (int i=0;i<=c;i++) {
        printf("seg %d: ", i);
        for (int j=0;j<T[i][0].size;j++) printf("%d ", T[i][0].get[j]);
        printf("\n");
    }
    // for (int i=1;i<=N;i++) {
    //     printf("%d (%d) head(%d): ", i, total[i], head[i]);
    //     for (int j=0;j<m;j++) printf("%3d ", BL[get(i, j)]);
    //     printf("\n");
    // }

    int *ANS = (int*) malloc(sizeof(int)*Q);
    for (int i=0;i<Q;i++) {
        printf("Answering %d %d %d\n", cities[i][0], cities[i][1], cities[i][2]);
        ANS[i] = query(cities[i][0], cities[i][1], adj, cities[i][2]);
    }
    return ANS;
}
