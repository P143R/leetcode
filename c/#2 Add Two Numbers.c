#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *merged = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *current = merged;

    int hold = 0;
    while (l1 != nullptr || l2 != nullptr || hold != 0) {
        current->val = 0;
        current->next = nullptr;

        if (l1 != nullptr) {
            current->val += l1->val;
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            current->val += l2->val;
            l2 = l2->next;
        }

        current->val += hold;

        hold = current->val / 10;
        current->val %= 10;

        if (l1 != nullptr || l2 != nullptr || hold != 0) {
            current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            current = current->next;
        }
    }

    return merged;
}

int main() {
    return 0;
}