/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void inorderTraversal(struct TreeNode* root, int* count, int k, int* result) {
    if (root == NULL || *count >= k) {
        return;
    }
    inorderTraversal(root->left, count, k, result);
    (*count)++;
    if (*count == k) {
        *result = root->val;
        return;
    }
    inorderTraversal(root->right, count, k, result);
}
int kthSmallest(struct TreeNode* root, int k) {
    int count = 0;
    int ans = 0;
    inorderTraversal(root, &count, k, &ans);
    return ans;
}