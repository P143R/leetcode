#include <stdlib.h>
#include <math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Leetcode
int countNodeMaxDepth(struct TreeNode *root, int count) {
    if (root == NULL)
        return count;

    int left = countNodeMaxDepth(root->left, count + 1);
    int right = countNodeMaxDepth(root->right, count + 1);

    return left > right ? left : right;
}

bool isBalanced(struct TreeNode *root) {
    if (root == NULL)
        return true;
    
    if (abs(countNodeMaxDepth(root->left, 0) - countNodeMaxDepth(root->right, 0)) > 1)
        return false;
    
    
    if (!isBalanced(root->left))
        return false;

    return isBalanced(root->right);
}
// !Leetcode

void destroyTree(struct TreeNode *root) {
    if (root == NULL)
        return;

    destroyTree(root->left);

    destroyTree(root->right);
    
    free(root);
}

int main() {
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 3;
    root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->val = 9;
    root->left->left = NULL;
    root->left->right = NULL;

    root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->val = 20;
    root->right->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->left->val = 15;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->left->val = 7;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    
    destroyTree(root);

    return 0;
}