#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct {
    int* data;
    int size;
    int capacity;
} SortedQueue;

void insert(SortedQueue* q, int value, int at) {
    if (q->capacity == q->size) {
        q->capacity *= 2;
        q->data = (int*)realloc(q->data, sizeof(int) * q->capacity);
    }

    for (int i = q->size; i > at; i--)
        q->data[i] = q->data[i - 1];

    q->data[at] = value;
    q->size++;
}

void pop(SortedQueue* q) { q->size--; }

int lowerBound(SortedQueue q, int value) {
    int left = 0;
    int right = q.size;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (q.data[mid] > value)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* res = NULL;
    struct ListNode* current;

    SortedQueue q;
    q.size = 0;
    q.capacity = 2;
    q.data = (int*)malloc(sizeof(int) * q.capacity);

    bool isEmpty = true;

    for (int i = 0; i < listsSize; i++) {
        if (lists[i] != NULL) {
            insert(&q, lists[i]->val, lowerBound(q, lists[i]->val));
            lists[i] = lists[i]->next;

            isEmpty = false;
        }
    }

    while (q.size != 0) {
        if (!isEmpty) {
            isEmpty = true;

            for (int i = 0; i < listsSize; i++) {
                if (lists[i] != NULL) {
                    insert(&q, lists[i]->val, lowerBound(q, lists[i]->val));
                    lists[i] = lists[i]->next;

                    isEmpty = false;
                }
            }
        }

        if (res == NULL) {
            res = (struct ListNode*)malloc(sizeof(struct ListNode));
            res->next = NULL;
            current = res;
        }
        
        current->val = q.data[q.size - 1];
        pop(&q);

        if (q.size != 0) {
            current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            current = current->next;
            current->next = NULL;
        }
    }

    free(q.data);

    return res;
}

int main() {
    return 0;
}