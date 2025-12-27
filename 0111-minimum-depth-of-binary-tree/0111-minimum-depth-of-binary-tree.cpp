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
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        if(!root->left && !root->right) return 1;
        int maxl=INT_MAX;
        if(root->left) {
            maxl = minDepth(root->left);
        }
        int maxr = INT_MAX;
        if(root->right){
            maxr = minDepth(root->right);
        }

        return 1+ min(maxr,maxl);
    }
};