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
    int ans = INT_MIN;
    // First of pair is min and second one is max
        pair<int,int> func(TreeNode* root){

        if(!root) return {INT_MAX,INT_MIN};
        if(root && !root->right && !root->left) return {root->val,root->val};

        auto left = func(root->left);
        auto right = func(root->right);

        int mini = min(root->val,min(left.first,right.first));
        int maxi = max(root->val,max(left.second,right.second));

        ans = max({ans ,abs(root->val - mini),abs(root->val-maxi)});

        return {mini,maxi};

    }
    
    int maxAncestorDiff(TreeNode* root) {
        func(root);
        return ans;
    }
};