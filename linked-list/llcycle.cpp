#include <iostream>
#include <new>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p1 = head;
        ListNode *p2 = head;

        while (p2->next != NULL and p2->next->next != NULL) {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2) {
                p1 = head;
                while (p1 != p2) {
                    p1 = p1->next;
                    p2 = p2->next;
                }
                return p1;
            }
        }
        return NULL;
    }
};

int
main(int argc, char *argv[])
{
    Solution s;
    ListNode root = ListNode(0);
    ListNode one = ListNode(1);
    ListNode two = ListNode(2);
    ListNode three = ListNode(3);
    ListNode four = ListNode(4);
    ListNode five = ListNode(5);
    ListNode *result;

    root.next = &one;
    one.next = &two;
    two.next = &three;
    three.next = &one;
    // four.next = &five;
    printf("root: %p -> %p\n", &root, root.next);
    printf("one:  %p -> %p\n", &one, one.next);
    printf("two : %p -> %p\n", &two, two.next);
    printf("thre: %p -> %p\n", &three, three.next);
    printf("four: %p -> %p\n", &four, four.next);
    printf("five: %p -> %p\n", &five, five.next);

    result = s.detectCycle(&root);

    cout << "result is " << result << endl;
}
