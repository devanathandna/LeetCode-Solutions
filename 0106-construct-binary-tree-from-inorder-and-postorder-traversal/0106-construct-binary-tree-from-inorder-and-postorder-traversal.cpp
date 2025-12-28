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
    int n;
    int index;
    TreeNode* func(vector<int>& inorder,vector<int>&postorder,unordered_map<int,int>&mpp,int l,int r){
        if(l>r) return nullptr;

        int value = postorder[index--];
        TreeNode* root = new TreeNode(value);
        int mid = mpp[value];

        root->right = func(inorder,postorder,mpp,mid+1,r);
        root->left = func(inorder,postorder,mpp,l,mid-1);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]] = i;
        }
        n = postorder.size();
        index = n-1;
        return func(inorder,postorder,mpp,0,inorder.size()-1);
    }
};