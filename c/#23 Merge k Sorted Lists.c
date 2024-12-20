#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeLists(struct ListNode *a, struct ListNode *b) {
    if (a == NULL)
        return b;

    if (b == NULL)
        return a;
    
    if (a->val < b->val) {
        a->next = mergeLists(a->next, b);
        
        return a;
    }
    
    b->next = mergeLists(a, b->next);
    
    return b;
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (listsSize == 0)
        return NULL;
    else if (listsSize == 1)
        return *lists;

    int mid = listsSize / 2;

    struct ListNode *left = mergeKLists(lists, mid);
    struct ListNode *right = mergeKLists(lists + mid, listsSize - mid);
    
    return mergeLists(left, right);
}

int main() {
    struct ListNode *lists[3];
    lists[0] = (struct ListNode *)malloc(sizeof(struct ListNode));
    lists[0]->val = 1;
    lists[0]->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    lists[0]->next->val = 4;
    lists[0]->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    lists[0]->next->next->val = 5;
    lists[0]->next->next->next = NULL;

    lists[1] = (struct ListNode *)malloc(sizeof(struct ListNode));
    lists[1]->val = 1;
    lists[1]->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    lists[1]->next->val = 3;
    lists[1]->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    lists[1]->next->next->val = 4;
    lists[1]->next->next->next = NULL;

    lists[2] = (struct ListNode *)malloc(sizeof(struct ListNode));
    lists[2]->val = 2;
    lists[2]->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    lists[2]->next->val = 6;
    lists[2]->next->next = NULL;

    struct ListNode *merged = mergeKLists(lists, 3);

    while (merged != NULL) {
        struct ListNode *temp = merged;
        merged = merged->next;

        free(temp);
    }

    return 0;
}