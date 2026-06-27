/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        int a = root->val;
        if(a < p->val && a < q->val) return lowestCommonAncestor(root->right,p,q);
        if(a > p->val && a > q->val) return lowestCommonAncestor(root->left,p,q);
        return root;
    }
};