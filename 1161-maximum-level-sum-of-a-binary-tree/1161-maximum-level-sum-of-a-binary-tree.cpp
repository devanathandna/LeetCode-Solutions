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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        int level=1;
        queue<TreeNode*>q;
        q.push(root);
        int max_level=0;
        int max_count=INT_MIN;

        while(!q.empty()){
            int r= q.size();
            int sum=0;
            for(int i=0;i<r;i++){
                TreeNode * node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            cout << sum << " "; 
            if(max_count < sum){
                max_count = sum;
                max_level = level;
            }
            level++;
        }

        return max_level;
    }
};