#include <stdio.h>
#include <unistd.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     struct ListNode *next;
};

static void
printList(struct ListNode *p)
{
	int i = 0;
	while (p) {
		printf("[%d] %p val:%d next:%p\n", i++, p, p->val, p->next);
		p = p->next;
	}
}

/* Note that this modifies both lists */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p = NULL;
    struct ListNode *head = NULL;

    if (l1 == NULL) {
        return(l2);
    } else if (l2 == NULL) {
        return(l1);
    }

	if (l1->val <= l2->val) {
		p = l1;
		head = l1;
		l1 = l1->next;
	} else { /* l2->val < l1->val */
		p = l2;
		head = l2;
		l2 = l2->next;
	}
	while (l1 && l2) {
		if (l1->val <= l2->val) {
			p->next = l1;
			l1 = l1->next;
		} else { /* l2->val < l1->val */
			p->next = l2;
			l2 = l2->next;
		}
		p = p->next;
	}
	p->next = l1 ? l1 : l2;
    return(head);
}

int
main(int argc, char *argv[])
{
	struct ListNode l1[3];
	struct ListNode l2[3];
	struct ListNode *p;

	l1[0].val = 1;
	l1[0].next = &l1[1];
	l1[1].val = 2;
	l1[1].next = &l1[2];
    l1[2].val = 4;
	l1[2].next = NULL;

	l2[0].val = 1;
	l2[0].next = &l2[1];
	l2[1].val = 3;
	l2[1].next = &l2[2];
    l2[2].val = 4;
	l2[2].next = NULL;

	printList(&l1[0]);
	printList(&l2[0]);
	p = mergeTwoLists(&l1[0], &l2[0]);
	printf("Result:\n");
	printList(p);
	return(0);
}
