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
    int goodNodes(TreeNode* root) {
        if (root == NULL) return 0;
        return dfs(root, root->val);
    }
    int dfs(TreeNode* node, int m) {
        if (node == NULL) return 0;
        int c = 0;
        if (node->val >= m) c++;
        int n = max(m, node->val);
        return c + dfs(node->left, n) + dfs(node->right, n);
    }
};
