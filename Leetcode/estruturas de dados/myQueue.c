#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    struct Node *first;
    struct Node *last;
} Queue;

Queue newQueue()
{
    Queue q;
    q.first = NULL;
    q.last = NULL;
    return q;
}

bool isEmpty(Queue queue)
{
    return queue.first == NULL;
}

void push(Queue *queue, int value)
{   
    Node *new = malloc(sizeof(Node));
    new->data = value;
    new->next = NULL;
    
    if (isEmpty(*queue))
    {
        queue->first = new;
        queue->last = new;
    } else 
    {
        queue->last->next = new;
        queue->last = new;
    }
}

void pop(Queue *queue)
{
    if (isEmpty(*queue)) 
    {
        puts("Lista vazia.");
        return;
    }
    Node *temp = queue->first;
    queue->first = queue->first->next;
    free(temp);
}

void reset(Queue *queue)
{
    Node *p = queue->first;
    Node *temp = p;
    while (p != NULL)
    {
        temp = p;
        p = p->next;
        free(temp);
    }

    queue->first = NULL;
    queue->last = NULL;
}

void show(Queue queue)
{
    Node *p = queue.first;
    printf("\n[ ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("]\n");
}

int main()
{
    Queue fila = newQueue();
    push(&fila, 1);
    push(&fila, 2);
    push(&fila, 3);
    push(&fila, 4);
    push(&fila, 5);
    push(&fila, 6);
    pop(&fila);
    pop(&fila);
    pop(&fila);
    pop(&fila);

    show(fila);
}