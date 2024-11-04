#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
} *front = NULL, *rear = NULL, *ptr;

typedef struct node N;

int size = 0;

void create_CLL() {
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

void insert_rear(int key) {
    size++;
    ptr = (N*)malloc(sizeof(N));
    ptr->data = key;
    ptr->next = NULL;
    if ( front == NULL ) {
        front = rear = ptr;
    } else {
        rear->next = ptr;
        rear = ptr;
    }
    rear->next = front;
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
    front = rear->next = ptr;
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
        rear->next = front;
    }
    free(ptr);
}

void delete_rear() {
    if ( rear == NULL ) {
        printf("Underfloq\n");
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
    temp->next = front;
    rear = temp;
    free(ptr);
}

void display() {
    if ( front == NULL ) {
        printf("Empty\n");
        return;
    }
    printf("Elements in the CLL : ");
    ptr = front;
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while ( ptr!=front );
    printf("\n");
}

void insert_pos(int pos, int key) {
    if ( pos <= 0 || pos > size ) {
        printf("Invalid position!\n");
        return;
    }
    if ( pos == 1 ) {
        insert_front(key);
        return;
    }
    size++;
    ptr = (N*)malloc(sizeof(N));
    ptr->next = NULL;
    ptr->data = key;
    N* temp = front;
    for ( int i=2 ; i<pos ; i++ ) {
        temp = temp->next;
    }
    ptr->next = temp->next;
    temp->next = ptr;
}

void delete_pos(int pos) {
    if ( pos <= 0 || pos > size ) {
        printf("Invalid position!\n");
        return;
    }
    if ( pos == 1 ) {
        delete_front();
        return;
    }
    size--;
    N* temp = front;
    for ( int i=2 ; i<pos ; i++ ) {
        temp = temp->next;
    }
    ptr = temp->next;
    printf("Deleted element : %d\n", ptr->data);
    temp->next = ptr->next;
    free(ptr);
}

void main() {
    int op, key, pos;
    printf("Creating Circular LL :\n");
    create_CLL();
    while ( 1 ) {
        printf("1.Insert\t2.Delete\t3.Display\t4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &op);
        switch(op) {
            case 1 : {
                printf("1.Front 2.Rear 3.Specific Position\n");
                printf("Enter : ");
                scanf("%d", &op);
                printf("Enter element : ");
                scanf("%d", &key);
                switch(op) {
                    case 1: 
                        insert_front(key);
                        break;
                    case 2:
                        insert_rear(key);
                        break;
                    case 3:
                        printf("Enter position : ");
                        scanf("%d", &pos);
                        insert_pos(pos, key);
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;
            }
            case 2 : {
                printf("1.Front 2.Rear 3.Specific Position\n");
                printf("Enter : ");
                scanf("%d", &op);
                switch(op) {
                    case 1: 
                        delete_front();
                        break;
                    case 2:
                        delete_rear();
                        break;
                    case 3:
                        printf("Enter position : ");
                        scanf("%d", &pos);
                        delete_pos(pos);
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
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