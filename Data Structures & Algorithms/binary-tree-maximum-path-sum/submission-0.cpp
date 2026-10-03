/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int m = INT_MIN;
        dfs(root, m);
        return m;
    }
    int dfs(TreeNode* node, int& m) {
        if (node == NULL)
            return 0;
        int l = max(0, dfs(node->left, m));
        int r = max(0, dfs(node->right, m));
        int c = l + node->val + r;
        m = max(m, c);
        return node->val + max(l, r);
    }
};