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
    bool func(TreeNode* leftn ,TreeNode* rightn){
        if(leftn==NULL || rightn==NULL){
            return leftn==rightn;
        }

        return (leftn->val==rightn->val) && func(leftn->left,rightn->right) && func(leftn->right,rightn->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return func(root->left,root->right);
        
    }
};