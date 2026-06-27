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
    bool func(TreeNode* root,long rightmax,long leftmin){
        if(!root) return true;

        if(root->val <= leftmin || root->val >= rightmax) return false;


        return func(root->left,root->val,leftmin) && func(root->right,rightmax,root->val);

    }
    bool isValidBST(TreeNode* root) {
       
        return func(root,LLONG_MAX,LLONG_MIN);
    }
};