#include <stdio.h>
#include <stdlib.h>

struct ListNode {
      int val;
      struct ListNode* next;
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

int main() {

    struct ListNode* l1 = malloc(sizeof(struct ListNode));
    l1->val = 2;
    l1->next = malloc(sizeof(struct ListNode));
    l1->next->val = 4;
    l1->next->next = malloc(sizeof(struct ListNode));
    l1->next->next->val = 3;
    l1->next->next->next = NULL;

    struct ListNode* l2 = malloc(sizeof(struct ListNode));
    l2->val = 5;
    l2->next = malloc(sizeof(struct ListNode));
    l2->next->val = 6;
    l2->next->next = malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;

    struct ListNode* result = addTwoNumbers(l1, l2);

    printf("Result: ");

    while (result != NULL) {
        printf("%d ", result->val);
        result = result->next;
    }
    printf("\n");

    return 0;
}