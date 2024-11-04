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

N* poly_add(N* p1, N* p2) {
    N *t1 = p1, *t2 = p2, *res = NULL, *temp = NULL; // temp for previous of res

    //Case 1 - Any poly can be empty.
    if ( t1 == NULL ) {
        return t2;
    }
    if ( t2 == NULL ) {
        return t1;
    }

    //Case 2 - Both poly have terms.
    while ( t1!=NULL && t2!=NULL ) {
        if ( res == NULL ) {
            res = (N*)malloc(sizeof(N));
            temp = res;
        } else {
            temp->next = (N*)malloc(sizeof(N));
            temp = temp->next;
        }

        if ( t1->exp == t2->exp ) {
            temp->coe = t1->coe + t2->coe;
            temp->exp = t1->exp;
            t1 = t1->next;
            t2 = t2->next;
        } else if ( t1->exp > t2->exp ) {
            temp->coe = t1->coe;
            temp->exp = t1->exp;
            t1 = t1->next;
        } else {
            temp->coe = t2->coe;
            temp->exp = t2->exp;
            t2 = t2->next;
        }
    }

    //Case 3 - Poly 1 rem terms.
    while ( t1!=NULL ) {
        temp->next = (N*)malloc(sizeof(N));
        temp = temp->next;
        temp->coe = t1->coe;
        temp->exp = t1->exp;
        t1 = t1->next;
    }

    //Case 4 - Poly 2 rem terms.
    while ( t2!=NULL ) {
        temp->next = (N*)malloc(sizeof(N));
        temp = temp->next;
        temp->coe = t2->coe;
        temp->exp = t2->exp;
        t2 = t2->next;
    }

    temp->next = NULL;
    return res;
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

void main() {
    printf("\nFor Polynomial 1 : \n");
    N* p1 = create_poly();
    printf("\nFor Polynomial 2 : \n");
    N* p2 = create_poly();
    N* p3 = poly_add(p1, p2);
    printf("\n\nPolynomial 1 : ");
    display(p1);
    printf("\n\nPolynomial 2 : ");
    display(p2);
    printf("\n\nResultant Polynomial : ");
    display(p3);
}