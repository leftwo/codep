#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

void
plist(struct ListNode *lp)
{
    while (lp) {
        printf("%d ", lp->val);
        lp = lp->next;
    }
    printf("\n");
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode *a = NULL;
    struct ListNode *head = NULL;
    int carry = 0;

    plist(l1);
    plist(l2);
    do {
        if (head == NULL) {
            a = malloc(sizeof(struct ListNode));
            head = a;
        } else {
            a->next = malloc(sizeof(struct ListNode));
            a = a->next;
        }
        int l1v;
        int l2v;

        if (l1) {
            l1v = l1->val;
            l1 = l1->next;
        } else {
            l1v = 0;
        }

        if (l2) {
            l2v = l2->val;
            l2 = l2->next;
        } else {
            l2v = 0;
        }
        a->val = l1v + l2v + carry;
        printf("%p ->val = %d + %d + %d= %d\n",
            a, l1v, l2v, carry, a->val % 10);
        carry = a->val / 10;
        a->val = a->val % 10;
        a->next = NULL;
    } while (l1 || l2);

    return (head);
}

int
main (int argc, char *argv[])
{
    struct ListNode l1;
    struct ListNode l2;
    struct ListNode *lp;

    struct ListNode *a;

    lp = &l1;
    lp->val = 2;
    lp->next = malloc(sizeof(struct ListNode));
    lp = lp->next;
    lp->val = 4;
    lp->next = malloc(sizeof(struct ListNode));
    lp = lp->next;
    lp->val = 3;
    lp->next = malloc(sizeof(struct ListNode));
    lp = lp->next;
    lp->val = 7;
    lp->next = NULL;


    lp = &l2;
    lp->val = 5;
    lp->next = malloc(sizeof(struct ListNode));
    lp = lp->next;
    lp->val = 6;
    lp->next = malloc(sizeof(struct ListNode));
    lp = lp->next;
    lp->val = 4;
    lp->next = NULL;

    a = addTwoNumbers(&l1, &l2);
    plist(a);
}
