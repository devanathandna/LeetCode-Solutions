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
    vector<string>result;
    int binaryconvert(string s){
        int val=0;
        for(char c:s){
            val = val*2 + (c-'0');
        }
        return val;
    }
    void func(TreeNode* root,string res){
        if(!root) return;
        if(!root->left && !root->right){
            res+=to_string(root->val);
            result.push_back(res);
            return;
        }
        func(root->left,res+to_string(root->val));
        func(root->right,res+to_string(root->val));

        
    }
    int sumRootToLeaf(TreeNode* root) {
        string res="";
        func(root,res);
        int ans=0;
        for(string s:result){
            ans+=binaryconvert(s);
        }
        return ans;
    }
};