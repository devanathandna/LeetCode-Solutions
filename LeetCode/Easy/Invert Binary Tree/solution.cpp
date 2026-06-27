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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* val = q.front();
            q.pop();
            swap(val->left,val->right);
            if(val->left) q.push(val->left);
            if(val->right) q.push(val->right);
        }
        return root;
    }
};