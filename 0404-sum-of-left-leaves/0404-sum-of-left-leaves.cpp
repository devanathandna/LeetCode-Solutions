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
    int sum;
    void dfs(TreeNode* root,bool a){
        if(!root) return;

        if(!root->left && !root->right && a){
            sum+=root->val;
        }

        dfs(root->left,true);
        dfs(root->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        if(root && !root->left && !root->right) return 0;
        sum=0;
        dfs(root,true);
        return sum;
    }
};