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
    int func(TreeNode* root){
        if(!root) return 0;
        int l = func(root->left);
        if(l==-1) return -1;
        int r = func(root->right);
        if(r==-1) return -1;
        if(abs(l-r)>1) return -1;

        return max(l,r)+1;

        
    }
    bool isBalanced(TreeNode* root) {
        int a = func(root);
        if(a==-1) return false;
        return true;
    }
};