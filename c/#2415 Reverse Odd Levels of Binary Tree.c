#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Leetcode
void postOrderTraversal(struct TreeNode *left, struct TreeNode *right, uint8_t level) {
    if (left == NULL || right == NULL) 
        return;

    postOrderTraversal(left->left, right->right, level + 1);
    postOrderTraversal(left->right, right->left, level + 1);

    if (level % 2 != 0) {
        left->val = left->val ^ right->val;
        right->val = left->val ^ right->val;
        left->val = left->val ^ right->val;
    }
}

struct TreeNode *reverseOddLevels(struct TreeNode *root) {
    if (root == NULL)
        return NULL;

    postOrderTraversal(root->left, root->right, 1);

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