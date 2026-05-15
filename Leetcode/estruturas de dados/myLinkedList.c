#include <stdio.h>
#include <stdlib.h>

//Lista encadeada com sentinela

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct List
{
    struct Node *first;
    unsigned int size;
} List;

List newList(int data)
{
    List list;
    list.first = malloc(sizeof(Node));
    list.first->data = data;
    list.first->next = NULL;
    list.size = 1;

    return list;
}

void push(List *list, int data, unsigned int index) 
{
    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;

    int counter = 0;
    Node *p = list->first;

    if (!list->first && index == 0)
    {
        list->first = new;
        list->size++;
    }

    if (index == 0) 
    {
        Node *temp = list->first;
        temp->next = list->first->next;

        list->first = new;
        new->next = temp;
        list->size++;
        return;
    }

    while (counter < index - 1 && p->next != NULL && counter < list->size)
    {
        p = p->next; 
        counter++;
    }

    new->next = p->next;
    p->next = new;
    list->size++;
}

void pop(List *list, unsigned int index) 
{
    if (!list->first) 
    {
        puts("Lista vazia.");
        return;
    }
    if (index >= list->size || index < 0) 
    {
        puts("Índice inválido.");
        return;
    }

    if (index == 0)
    {
        Node *temp = list->first;
        list->first = list->first->next;
        free(temp);

        list->size--;
        return;
    }

    int counter = 0;
    Node *p = list->first;
    
    while (counter < index - 1 && p->next != NULL && counter < list->size)
    {
        p = p->next; 
        counter++;
    }

    Node *temp = p->next;
    p->next = p->next->next;
    free(temp);

    list->size--;
}

void reset(List *list)
{
    while (list->size > 0)
    {
        pop(list, 0);
    }
}

void show(List list)
{
    if (!list.first) 
    {
        puts("Lista vazia.");
        return;
    }

    Node *p = list.first;
    printf("\n[ ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("]");
}