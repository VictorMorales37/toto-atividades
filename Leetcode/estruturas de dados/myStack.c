#include <stdbool.h>
#include <stdio.h>

#define MAX 100
//top starts as -1

typedef struct 
{
    int top;
    int data[MAX];
    
} Stack;

bool isEmpty(Stack stack)
{
    return stack.top == -1;
}

bool isFull(Stack stack)
{
    return stack.top == MAX - 1;
}

void push(Stack *stack, int value)
{
    if (!isFull(*stack))
    {
        stack->top++;
        stack->data[stack->top] = value;
    }
    else return;
}

void pop(Stack *stack)
{
    if (!isEmpty(*stack)) stack->top--;
    else return;
}

void reset(Stack *stack)
{
    stack->top = -1;
}

void show(Stack stack)
{
    if (isEmpty(stack)) 
    {
        puts("Pilha vazia.");
        return;
    }
    printf("\n[ ");
    for (int i = 0; i <= stack.top; i++)
    {
        printf("%d ", stack.data[i]);
    }
    printf("]");
}

Stack newStack()
{
    Stack stack;
    stack.top = -1;
    return stack;
}

int main()
{
    Stack pilha = newStack();
    push(&pilha, 1);
    push(&pilha, 2);
    push(&pilha, 3);
    push(&pilha, 4);
    push(&pilha, 5);

    pop(&pilha);
    pop(&pilha);
    pop(&pilha);
    pop(&pilha);
    pop(&pilha);

    show(pilha);
}