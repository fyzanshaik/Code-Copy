#include <stdio.h>
void main() {
    int alloc[10][10], req[10][10], need[10][10];
    int available[10], finish[10], sq[10], max_inst[10];
    int n, m, i, j, k, count;
    int count1 = 0;
    printf("\n Enter the number of processes running \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) finish[i] = 0;

    printf("\n Enter the number of resource types \n ");
    scanf("%d", &m);
    printf("\n Enter the maximum instances of each resouce type\n");
    for (i = 0; i < m; i++) scanf("%d", &max_inst[i]);

    printf("\n Enter the allocation Matrix \n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) scanf("%d", &alloc[i][j]);

    printf("\n Enter the Request Matrix \n");

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) scanf("%d", &req[i][j]);

    printf("\nEnter the no.of available instances of each  resource type\n");
    for (i = 0; i < m; i++) scanf("%d", &available[i]);

    do {
        for (k = 0; k < n; k++) {
            for (i = 0; i < n; i++) {
                if (finish[i] == 0) {
                    count = 0;
                    for (j = 0; j < m; j++) {
                        if (available[j] >= req[i][j]) count++;
                    }
                    if (count == m) {
                        count1++;
                        finish[i] = 1;
                        sq[count1 - 1] = i;
                        for (j = 0; j < m; j++) {
                            available[j] = available[j] + alloc[i][j];
                        }
                        break;
                    }
                }
            }
        }
        if (count1 != n) {
            printf("\n The current state is ** unsafe state **\n");
            break;
        }
    } while (count1 != n);
    if (count1 == n) {
        printf(" \n The Current  state is safe state \n");
        printf("\n The safe sequence is \n");
        for (i = 0; i < n; i++) printf("\tP[%d]", sq[i]);

        printf("\n The available matrix is \n");

        for (i = 0; i < m; i++) printf("\t%d", available[i]);
        printf("\n");
    }
    printf("The Processes Deadlocked are ");
    for (i = 0; i < n; i++) {
        if (finish[i] == 0) printf("P[%d]", i);
    }
}