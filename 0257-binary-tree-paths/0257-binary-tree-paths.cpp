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
    vector<string>ans;
        void func(TreeNode* root,string res){
            if(!root) return;

            if(!root->left && !root->right){
                res+=to_string(root->val);
                ans.push_back(res);
                return;
            }

            res+=to_string(root->val);
            res+="->";
            func(root->left,res);
            func(root->right,res);
        }
    vector<string> binaryTreePaths(TreeNode* root) {
        string res="";
        func(root,res);
        return ans;
    }
};