#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define maximum size of the stack

// Stack structure definition
typedef struct
{
    int items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack *s)
{
    s->top = -1;
}

// Function to check if the stack is full
int isFull(Stack *s)
{
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s)
{
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack is full. Cannot push %d\n", value);
    }
    else
    {
        s->items[++(s->top)] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    else
    {
        printf("%d popped from the stack.\n", s->items[s->top]);
        return s->items[(s->top)--];
    }
}

// Function to peek the top element of the stack
int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
    else
    {
        return s->items[s->top];
    }
}

// Function to display the stack contents
void display(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack contents: ");
        for (int i = 0; i <= s->top; i++)
        {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

// Main function to demonstrate stack operations
int main()
{
    Stack s;
    initialize(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    printf("Top element is %d\n", peek(&s));

    pop(&s);
    display(&s);

    return 0;
}
