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
    int i=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int s,int e){
        if(s>e) return NULL;
        int x=preorder[i];
        i++;
        TreeNode* a=new TreeNode(x);
        int m=0;
        for(int j=s;j<=e;j++){
            if(inorder[j]==x){
                m=j;
                break;
            }
        }
        a->left=build(preorder,inorder,s,m-1);
        a->right=build(preorder,inorder,m+1,e);
        return a;
    }
};
