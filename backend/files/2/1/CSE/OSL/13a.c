// FCFS disk scheduling algorithm
#include <stdio.h>
#include <stdlib.h>
void fcfs_disk_scheduling(int arr[], int n, int first) {
    int total_dist = 0;
    int distance, current;
    int i;
    for (i = 0; i < n; i++) {
        current = arr[i];
        distance = abs(current - first);

        total_dist += distance;
        first = current;
    }
    printf("Total seek distance is %d", total_dist);
    printf("\n The Seek Sequence is \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
int main() {
    int arr[100];
    int n, i;
    int start;
    printf("Enter the total number of cylinder requests in queue : ");
    scanf("%d", &n); // 4
    printf("Enter the cylinder numbers requested : ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);    // 100 200 300 150   
    }
    printf("Enter the initial head position : ");
    scanf("%d", &start);  // 50 
    fcfs_disk_scheduling(arr, n, start);  // 50 + 100 + 100 + 150 = 400
    return 0;
}