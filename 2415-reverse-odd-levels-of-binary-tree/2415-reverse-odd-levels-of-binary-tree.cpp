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
    void func(TreeNode* left,TreeNode* right,int depth){
        if(!left || !right) return;
        if(depth%2){
            swap(left->val,right->val);
        }
        func(left->left,right->right,depth+1);
        func(left->right,right->left,depth+1);
    } 
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return root;
        func(root->left,root->right,1);
        return root;
    }
};