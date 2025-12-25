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
    void insert(TreeNode* root,int val,int cur,int depth){
        if(!root) return;
        if(cur==depth-1){
            TreeNode*node = new TreeNode(val);
            node->left = root->left;
            root->left = node;

            TreeNode*nodee = new TreeNode(val);
            nodee->right = root->right;
            root->right = nodee;
        }
        else{
            insert(root->left,val,cur+1,depth);
            insert(root->right,val,cur+1,depth);

        }

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return root;
        if(depth==1){
            TreeNode*node = new TreeNode(val);
            node->left = root;
            return node;
        }
        else{
            insert(root,val,1,depth);
            return root;
        }

    }
};