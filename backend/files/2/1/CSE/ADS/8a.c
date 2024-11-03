#include<stdio.h>
#define SIZE 10

struct node {
    int data;
    struct node * next;
} *front = NULL , *rear = NULL , *temp ,*ptr ;

int min = -1;

typedef struct node Q;

void update_min() {
    temp = front->next;
    int small = temp->data;
    while ( temp!=NULL ) {
        if ( temp->data < small ) {
            small = temp->data;
        }
        temp = temp->next;
    }
    min = small;
}

void enqueue(int x) {
    ptr = (Q*)malloc(sizeof(Q));
    ptr->data = x;
    ptr->next = NULL;
    if ( front==NULL ) {
        front = rear = ptr;
        min = x;
        return;
    }
    rear->next = ptr;
    rear = ptr;
    if ( x<min ) {
        min = x;
    } 
}

void dequeue() {
    if ( front==NULL ) {
        return;
    }
    if ( front==rear ) {
        min = -1;
        temp = front;
        front = rear = NULL;
        free(temp);
        return;
    }
    update_min();
    temp = front;
    front = front->next;
    free(temp);
}

int peek() {
    return front->data;
}

int isEmpty() {
    return (front == NULL);
}

int vis[SIZE] = {0};

void print_graph(int g[SIZE][SIZE], int n) {
    for ( int i=0 ; i<n ; i++ ) {
        for ( int j=0 ; j<n ; j++ ) {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
}

void bfs(int g[SIZE][SIZE], int n, int src) {
    int v = src;
    vis[v] = 1;
    enqueue(v);
    while (!isEmpty()) {
        v = peek();
        dequeue();
        printf("%d ", v);
        for ( int i=0 ; i<n ; i++ ) {
            if ( g[v][i] && !vis[i] ) {
                enqueue(i);
                vis[i] = 1;
            }
        }
    }
}

void main() {
    int graph[SIZE][SIZE] = {0};
    int n = 0, src = 0, des = 0, edges = 0;
    printf("Enter n : ");
    scanf("%d", &n);
    if ( n>SIZE ) {
        printf("Size is smaller");
        exit(0);
    }

    // INPUT 1

    // for ( int i=0 ; i<n ; i++ ) {
    //     for ( int j=0 ; j<n ; j++ ) {
    //         if ( i!=j ) {
    //             printf("Graph[%d][%d]  : ", i+1, j+1);
    //             scanf("%d", &graph[i][j]);
    //         }
    //     }
    // } 

    // INPUT 2

    printf("Enter no. of edges : ");
    scanf("%d", &edges);
    for ( int i=0 ; i<edges ; i++ ) {
        printf("Edge no %d\n", i+1);
        printf("Enter src and des : ");
        scanf("%d %d", &src, &des);
        if ( des >= n || src >= n || des < 0 || src < 0 ) {
            printf("Invalid vertex!");
            exit(0);
        }
        graph[src][des] = graph[des][src] = 1;
    }

    print_graph(graph, n);

    printf("Enter source vertex for BFS : ");
    scanf("%d", &src);
    printf("BFS traversal starting from %d : \n", src);
    bfs(graph, n, src);
}