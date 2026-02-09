
class Solution {
public:
    vector<int>ans;
    int n;
    void func(TreeNode* root){
        if(root==NULL) return;
        ans.push_back(root->val);
        func(root->left);
        func(root->right);
    }
    void buildTree(int val,TreeNode* root){
       if(val < root->val){
        if(root->left) buildTree(val,root->left);
        else root->left = new TreeNode(val);
       }

       if(val > root->val){
        if(root->right) buildTree(val,root->right);
        else root->right = new TreeNode(val);
       }

    }
    TreeNode* balanceBST(TreeNode* root) {
        func(root);
        for(int i:ans){
            cout << i << " ";
        }
        sort(ans.begin(),ans.end());
        n = ans.size();
        int mid = n/2;
        TreeNode* node = new TreeNode(ans[mid]);
        for(int i=0;i<mid;i++){
            buildTree(ans[i],node);
        }
        for(int i=mid+1;i<n;i++){
            buildTree(ans[i],node);
        }


        return node;
    }
};