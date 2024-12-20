#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Leetcode
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *merged = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *current = merged;

    int hold = 0;
    while (l1 != NULL || l2 != NULL || hold != 0) {
        current->val = 0;
        current->next = NULL;

        if (l1 != NULL) {
            current->val += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            current->val += l2->val;
            l2 = l2->next;
        }

        current->val += hold;

        hold = current->val / 10;
        current->val %= 10;

        if (l1 != NULL || l2 != NULL || hold != 0) {
            current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            current = current->next;
        }
    }

    return merged;
}
// !Leetcode

int main() {
    return 0;
}