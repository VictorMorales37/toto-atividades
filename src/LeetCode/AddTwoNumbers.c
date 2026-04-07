#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *output = malloc(sizeof(struct ListNode));
    output->val = 0;
    output->next = NULL;

    struct ListNode *pOutput = output;
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;

    int carry = 0;
    
    while (p1 != NULL || p2 != NULL) {
        
        while (pOutput->next != NULL) {
            pOutput = pOutput->next;
        }

        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->val = 0;
        newNode->next = NULL;
        pOutput->next = newNode;

        if (p1 != NULL) {newNode->val += p1->val;}
        if (p2 != NULL) {newNode->val += p2->val;}
        newNode->val += carry;

        if (newNode->val >= 10) {
            carry = 1;
            newNode->val -= 10;
        }

        else {carry = 0;}

        if (p1 != NULL) {p1 = p1->next;}
        if (p2 != NULL) {p2 = p2->next;}
    }

    if (carry == 1) {

        pOutput = output;
        while (pOutput->next != NULL) {
            pOutput = pOutput->next;
        }

        struct ListNode *lastNode = malloc(sizeof(struct ListNode));
        lastNode->val = 1;
        lastNode->next = NULL;

        pOutput->next = lastNode;
    }

    return output->next;
}


int main(void) {

    struct ListNode * listA = malloc(sizeof(struct ListNode));
    listA->next = malloc(sizeof(struct ListNode));
    listA->next->next = malloc(sizeof(struct ListNode));
    
    struct ListNode * listB = malloc(sizeof(struct ListNode));
    listB->next = malloc(sizeof(struct ListNode));
    listB->next->next = malloc(sizeof(struct ListNode));

    listA->val = 2;
    listA->next->val = 4;
    listA->next->next->val = 3;

    listB->val = 5;
    listB->next->val = 6;
    listB->next->next->val = 4;
    
    struct ListNode * listC = addTwoNumbers(listA, listB);

    printf("[%d, %d, %d] ", listA->val, listA->next->val, listA->next->next->val);
    printf("+ [%d, %d, %d] ", listB->val, listB->next->val, listB->next->next->val);
    printf("= [%d, %d, %d]", listC->val, listC->next->val, listC->next->next->val);
}