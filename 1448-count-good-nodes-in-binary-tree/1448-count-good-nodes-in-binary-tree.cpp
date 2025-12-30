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
    int func(TreeNode*root,int a){
       if(!root) return 0;
        int count=0;
       if(root->val >=a){
        count+=1;
        a=root->val;
       }

       count+=func(root->left,a);
       count+=func(root->right,a);

       return count;
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return func(root,INT_MIN);
    }
};