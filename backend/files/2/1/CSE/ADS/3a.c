#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
} *front = NULL, *rear = NULL, *ptr, *temp;

typedef struct node N;

int size = 0;

void create_DEQUE() {
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
    size = n;
}

void insert_rear(int key) {
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
}

void insert_front(int key) {
    size++;
    ptr = (N*)malloc(sizeof(N));
    ptr->data = key;
    ptr->next = NULL;
    if ( front == NULL ) {
        front = rear = ptr;
        return;
    }
    ptr->next = front;
    front = ptr;
}

void delete_front() {
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
    }
    free(ptr);
}

void delete_rear() {
    if ( rear == NULL ) {
        printf("Underflow\n");
        return;
    }
    size--;
    printf("Deleted element : %d\n", rear->data);
    ptr = rear;
    if ( front == rear ) {
        front = rear = NULL;
        free(ptr);
        return;
    }
    N* temp = front;
    while ( temp->next != rear ) {
        temp = temp->next;
    }
    temp->next = NULL;
    rear = temp;
    free(ptr);
}

void display() {
    if ( front == NULL ) {
        printf("Empty\n");
        return;
    }
    printf("Elements in the DEQUE : ");
    temp = front;
    while ( temp!=NULL ) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main() {
    int op, key, pos;
    printf("Creating DEQUE :\n");
    create_DEQUE();
    while ( 1 ) {
        printf("1.Insert Front\t2.Insert Rear\t3.Delete Front\t4.Delete Rear\t5.Display\t6.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &op);
        switch(op) {
            case 1 : {
                printf("Enter element : ");
                scanf("%d", &key);
                insert_front(key);
                break;
            }
            case 2 : {
                printf("Enter element : ");
                scanf("%d", &key);
                insert_rear(key);
                break;
            }
            case 3 :
                delete_front();
                break;
            case 4 :
                delete_rear();
                break;
            case 5 :
                display();
                break;
            case 6 :
                printf("Exiting program...\n");
                exit(0);
            default :
                printf("Invalid choice!\n");
        }
    }
}