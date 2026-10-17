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
     vector<vector<int>> ans;
    vector<int> res;

    void dfs(TreeNode* root, int target, vector<int>& res) {
        if (!root) return;

        res.push_back(root->val);
        target -= root->val;

        if (target == 0 && !root->left && !root->right) {
            ans.push_back(res);
        } else {
            dfs(root->left, target, res);
            dfs(root->right, target, res);
        }

        res.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {


        dfs(root, targetSum, res);
        return ans;
    }
};