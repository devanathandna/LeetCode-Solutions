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
vector<int>ans;
    void func(TreeNode* root,int a){
        if(!root) return;
        if(!root->left && !root->right){
            a*=10;
            a+=root->val;
            ans.push_back(a);
        }
        func(root->left,a*10 + root->val);
        func(root->right,a*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        func(root,0);
        int total=0;
        for(int i:ans){
            total+=i;
        }
        return total;
    }
};