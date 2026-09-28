/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    bool isValidBST(TreeNode* root) {
        long long m = LLONG_MIN;
        long long n = LLONG_MAX;
        return dfs(root, m, n);
    }
    bool dfs(TreeNode* node, long long m, long long n) {
        if (node == NULL) return true;
        if (node->val <= m || node->val >= n) return false;
        return dfs(node->left, m, node->val) && dfs(node->right, node->val, n);
    }
};
