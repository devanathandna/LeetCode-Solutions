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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int r = q.size();
            double value = 0;
            for(int i=0;i<r;i++){
                TreeNode*node = q.front();q.pop();
                value+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            value = value/r;
            ans.push_back(value);
        }

        return ans;
    }
};