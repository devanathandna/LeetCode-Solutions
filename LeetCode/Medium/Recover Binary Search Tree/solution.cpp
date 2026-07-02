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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
    void func(TreeNode* root){
        if(!root) return;

        func(root->left);
        if(prev && prev->val > root->val){
            if(!first){
                first = prev;
                second = root;
            }
            else{
                second = root;
            }
        }
        prev = root;
        func(root->right);
    }

    void recoverTree(TreeNode* root) {
        func(root);
        swap(first->val,second->val);
        return;
    }
};