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
    vector<int>r1,r2;
    void leaf1(TreeNode* root){
        if(!root) return;
        if(!root->left && !root->right){
            r1.push_back(root->val);
        }
        leaf1(root->left);
        leaf1(root->right);
    }

    void leaf2(TreeNode* root){
        if(!root) return;
        if(!root->left && !root->right){
            r2.push_back(root->val);
        }
        leaf2(root->left);
        leaf2(root->right);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        leaf1(root1);
        leaf2(root2);
        if(r1.size()!=r2.size()) return false;
        for(int i=0;i<r1.size();i++){
            if(r1[i]!=r2[i]) return false;
        }
        return true;
        
    }
};