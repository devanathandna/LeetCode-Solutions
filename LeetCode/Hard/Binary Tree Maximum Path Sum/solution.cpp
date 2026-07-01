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
    int func(TreeNode* root,int &maxi){
        if(!root) return 0;
        int left = max(0,func(root->left,maxi));
        int right = max(0,func(root->right,maxi));
        maxi = max(left+right+root->val,maxi);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int a = func(root,maxi);
        return maxi;
    }
};