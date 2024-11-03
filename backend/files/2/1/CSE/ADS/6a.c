#include<stdio.h>
void swap(int arr[], int p, int q) {
    int temp = arr[p];
    arr[p] = arr[q];
    arr[q] = temp;
}

void make_max_heap(int arr[], int i, int n) {
    if ( i<0 ) {
        return;
    }
    int l, r, max;
    l = 2*i+1;
    r = 2*i+2;
    if ( l>=n ) {  // No child
        return;
    }
    max = l;  // Assuming left child has max val
    if ( r<n && arr[r] > arr[l] ) { // If right child exist and has max val than left
        max = r;
    }
    if ( arr[i] < arr[max] ) {
        swap(arr, i, max);
        make_max_heap(arr, max, n);
    }
    make_max_heap(arr, i-1, n);
}

void display(int arr[], int n) {
    for ( int i=0 ; i<n ; i++ ) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void heap_sort(int arr[], int n) {
    int last = n-1;
    make_max_heap(arr, n/2-1, n);
    while (last!=0) {
        swap(arr, 0, last);
        make_max_heap(arr, 0, last);
        last--;
    }
}

void main() {
    int n;
    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter elements : ");
    int arr[n];
    for ( int i=0 ; i<n ; i++ ) {
        scanf("%d", &arr[i]);
    }    
    printf("Before sort : ");
    display(arr, n);
    heap_sort(arr, n);
    printf("After sort : ");
    display(arr, n);
}