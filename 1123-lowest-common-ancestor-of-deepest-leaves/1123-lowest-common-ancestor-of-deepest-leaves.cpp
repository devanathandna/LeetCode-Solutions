
class Solution {
public:
    TreeNode* func(TreeNode* root,unordered_set<TreeNode*>&st){
        if(!root) return nullptr;
        if(st.count(root)) return root;


        TreeNode* left = func(root->left,st);
        TreeNode* right = func(root->right,st);

        if(left && right ) return root;

        return left ? left : right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*>q;
        q.push(root);
        vector<TreeNode*>level;

        while(!q.empty()){
            int r = q.size();
            level.clear();

            for(int i=0;i<r;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        unordered_set<TreeNode*>st(level.begin(),level.end());

        return func(root,st);
    }
};