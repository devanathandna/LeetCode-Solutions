
class Solution {
public:
    long long total = 0;
    long long ans = 0;
    int MOD = 1e9+7;
    long long calculate(TreeNode* root){
        if(!root) return 0;
        return root->val + calculate(root->left) + calculate(root->right);
    }
    long long func(TreeNode* root){
        if(!root) return 0;

        long long left = func(root->left);
        long long right = func(root->right);

        ans = max(ans, left *(total-left));
        ans = max(ans,right*(total-right));

        return left+right+root->val;
    }
    
    int maxProduct(TreeNode* root) {
        total = calculate(root);
        long long dummy = func(root);
        return ans % MOD;
    }
};