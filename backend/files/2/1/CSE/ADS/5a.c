#include<stdio.h>
#include<stdlib.h>

struct node {
    int coe;
    int exp;
    struct node * next;
};

typedef struct node N;

N* create_poly() {
    N *p = NULL, *temp = NULL; // temp for previous of p
    N *ptr = NULL;
    int n, e, c;
    printf("Enter No. of Terms : ");
    scanf("%d", &n);
    for ( int i=0 ; i<n ; i++ ) {
        ptr = (N*)malloc(sizeof(N));
        printf("Enter coefficient and exponent : ");
        scanf("%d %d", &c, &e);
        ptr->coe = c;
        ptr->exp = e;
        ptr->next = NULL;
        if ( p==NULL ) {
            p = temp = ptr;
        } else {
            temp->next = ptr;
            temp = ptr;
        }
    }
    return p;
}

void display( N* head) {
    N* t = head;
    if ( t==NULL ) {
        printf("NULL!");
        return;
    }
    while ( t->next != NULL ) {
        printf("%d X^%d  +  ", t->coe, t->exp);
        t = t->next;
    }
    printf("%d X^%d  = 0\n", t->coe, t->exp);
}

N* poly_mul(N* p1, N* p2) {
    N *t1 = p1, *t2 = p2, *last = NULL, *res = NULL, *temp;
    while ( t1!=NULL ) {
        t2 = p2;
        while (t2!=NULL) {
            temp = (N*)malloc(sizeof(N));
            temp->coe = (t1->coe)*(t2->coe);
            temp->exp = t1->exp + t2->exp;
            temp->next = NULL;
            if ( res == NULL ) {
                res = last = temp;
            } else {
                last->next = temp;
                last = temp;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    t1 = res;
    while ( t1!=NULL ) {
        temp = t1;
        t2 = t1->next;
        while ( t2!=NULL ) {
            if ( t1->exp == t2->exp ) {
                t1->coe += t2->coe;
                temp->next = t2->next;
            }
            temp = t2;
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    return res;
}

void main() {
    printf("\nFor Polynomial 1 : \n");
    N* p1 = create_poly();

    printf("\nFor Polynomial 2 : \n");
    N* p2 = create_poly();

    N* p3 = poly_mul(p1, p2);

    printf("\n\nPolynomial 1 : ");
    display(p1);

    printf("\n\nPolynomial 2 : ");
    display(p2);
    
    printf("\n\nResultant Polynomial : ");
    display(p3);
}