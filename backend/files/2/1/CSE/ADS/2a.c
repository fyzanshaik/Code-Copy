#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
} *front = NULL, *rear = NULL, *ptr, *temp;

typedef struct node N;

int size = 0;

void create_CQ() {
    int n;
    printf("Enter no. of elements : ");
    scanf("%d", &n);
    for ( int i=0 ; i<n ; i++ ) {
        printf("Enter element : ");
        ptr = (N*)malloc(sizeof(N));
        scanf("%d", &ptr->data);
        ptr->next = NULL;
        if ( front == NULL ) {
            front = rear = ptr;
        } else {
            rear->next = ptr;
            rear = ptr;
        }
    }
    if ( n>0 ) {
        rear->next = front;
        size = n;
    }
}

void Enqueue(int key) {
    size++;
    ptr = (N*)malloc(sizeof(N));
    ptr->data = key;
    ptr->next = NULL;
    if ( front == NULL ) {
        front = rear = ptr;
        return;
    }
    rear->next = ptr;
    rear = ptr;
    rear->next = front;
}

void Dequeue() {
    if ( front == NULL ) {
        printf("Underflow\n");
        return;
    }
    size--;
    printf("Deleted element : %d\n", front->data);
    ptr = front;
    if ( front == rear ) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }
    free(ptr);
}

void display() {
    if ( front == NULL ) {
        printf("Empty\n");
        return;
    }
    printf("Elements in the Circular Queue : ");
    ptr = front;
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while ( ptr!=front );
    printf("\n");
}

void main() {
    int op, key;
    printf("Creating Circular Queue :\n");
    create_CQ();
    while ( 1 ) {
        printf("1.Enqueue\t2.Dequeue\t3.Display\t4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &op);
        switch(op) {
            case 1 : {
                printf("Enter element : ");
                scanf("%d", &key);
                Enqueue(key);
                break;
            }
            case 2 : {
                Dequeue();
                break;
            }
            case 3 :
                display();
                break;
            case 4 :
                printf("Exiting the program ... \n");
                exit(0);
            default :
                printf("Invalid choice!\n");
        }
    }
}