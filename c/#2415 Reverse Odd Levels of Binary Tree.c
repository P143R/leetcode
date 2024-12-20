#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Leetcode
void reverse(struct TreeNode *current[], int size) {
    int i = 0;
    int j = size - 1;
    while (i < size / 2) {
        int temp = current[i]->val;
        current[i]->val = current[j]->val;
        current[j]->val = temp;

        i++;
        j--;
    }
}

struct TreeNode *reverseOddLevels(struct TreeNode *root) {
    struct TreeNode *queue[1 << 15];
    struct TreeNode *currentLevel[1 << 13];

    int front = 0;
    int rear = 0;
    int size = 0;
    int level = 0;

    queue[rear++] = root;
    queue[rear++] = NULL;

    while (front != rear) {
        struct TreeNode *t = queue[front++];

        if (t == NULL) {
            if (level % 2 != 0) {
                reverse(currentLevel, size);
                size = 0;
            }
            
            if (front == rear)
                break;

            queue[rear++] = NULL;

            level++;
            continue;
        }

        if (level % 2 != 0)
            currentLevel[size++] = t;

        if (t->left != NULL) 
            queue[rear++] = t->left;


        if (t->right != NULL) 
            queue[rear++] = t->right;
    }

    return root;
}
// !Leetcode

struct TreeNode *createNode(int val) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode *insertLevelOrder(int *arr, int size, int index) {
    if (index >= size || arr[index] == -1)
        return NULL;

    struct TreeNode *root = createNode(arr[index]);

    root->left = insertLevelOrder(arr, size, 2 * index + 1);
    root->right = insertLevelOrder(arr, size, 2 * index + 2);

    return root;
}

int main() {
    int arr[] = {2,3,5,8,13,21,34,40,41,42,43,44,45,46,47};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct TreeNode *root = insertLevelOrder(arr, size, 0);
    root = reverseOddLevels(root);

    return 0;
}