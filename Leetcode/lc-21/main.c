#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    
    struct ListNode* mergedList = malloc(sizeof(struct ListNode));
    mergedList->next = NULL;

    struct ListNode* pM = mergedList;
    struct ListNode* p1 = list1;
    struct ListNode* p2 = list2;

    while (p1 != NULL || p2 != NULL)
    {
        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        newNode->next = NULL;

        while (pM->next != NULL) pM = pM->next;
        pM->next = newNode;

        if (p1 != NULL && p2 == NULL)
        {
            newNode->val = p1->val;
            p1 = p1->next;
        }

        else if (p1 == NULL && p2 != NULL)
        {
            newNode->val = p2->val;
            p2 = p2->next;
        }

        else if (p1->val > p2->val)
        {
            newNode->val = p2->val;
            p2 = p2->next;
        }
        else if (p1->val < p2->val)
        {
            newNode->val = p1->val;
            p1 = p1->next;
        }
        else if (p1->val == p2->val)
        {
            newNode->val = p1->val;
            p1 = p1->next;

            struct ListNode* newestNode = malloc(sizeof(struct ListNode));
            
            newNode->next = newestNode;
            newestNode->next = NULL;
            newestNode->val = p2->val;
            p2 = p2->next;
        } 
    }

    return mergedList->next;
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //list1: 1 -> 2 -> 4
    struct ListNode* list1 = malloc(sizeof(struct ListNode));
    list1->val = 1;
    list1->next = malloc(sizeof(struct ListNode));
    list1->next->val = 2;
    list1->next->next = malloc(sizeof(struct ListNode));
    list1->next->next->val = 4;
    list1->next->next->next = NULL;

    //list2: 1 -> 3 -> 4
    struct ListNode* list2 = malloc(sizeof(struct ListNode));
    list2->val = 1;
    list2->next = malloc(sizeof(struct ListNode));
    list2->next->val = 3;
    list2->next->next = malloc(sizeof(struct ListNode));
    list2->next->next->val = 4;
    list2->next->next->next = NULL;

    printf("List 1: ");
    struct ListNode* temp = list1;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("List 2: ");
    temp = list2;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");

    struct ListNode* merged = mergeTwoLists(list1, list2);

    printf("Merged: ");
    temp = merged;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}