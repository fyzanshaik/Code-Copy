#include<stdio.h>
#define SIZE 10

int G[SIZE][SIZE] = {0};
int n = 0;

int vis[SIZE] = {0};

void print_graph() {
    for ( int i=0 ; i<n ; i++ ) {
        for ( int j=0 ; j<n ; j++ ) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
}

void DFS(int u) {
    vis[u] = 1;
    printf("%d ", u+1);
    for ( int i=0 ; i<n ; i++ ) {
        if (G[u][i] && !vis[i]) {
            DFS(i);
        }
    }
}

void main() {
    int src = 0, des = 0, edges = 0;
    printf("Enter n : ");
    scanf("%d", &n);
    if ( n>SIZE ) {
        printf("Size is smaller");
        exit(0);
    }

    // INPUT 2

    printf("Enter no. of edges : ");
    scanf("%d", &edges);
    for ( int i=0 ; i<edges ; i++ ) {
        printf("Edge no %d\n", i+1);
        printf("Enter src and des : ");
        scanf("%d %d", &src, &des);
        if ( des > n || src > n || des < 1 || src < 1 ) {
            printf("Invalid vertex!");
            exit(0);
        }
        G[src-1][des-1] = G[des-1][src-1] = 1;
    }

    print_graph(G, n);

    printf("Enter source vertex for DFS : ");
    scanf("%d", &src);
    printf("DFS traversal starting from %d : \n", src);
    DFS(src-1);
}