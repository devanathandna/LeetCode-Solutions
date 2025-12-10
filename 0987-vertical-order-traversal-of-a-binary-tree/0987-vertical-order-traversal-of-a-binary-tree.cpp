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
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0] == b[0] && a[1]==b[1]){
            return a[2] < b[2];
        }
        else if(a[0] == b[0]){
            return a[1] < b[1];
        }

        return a[0] < b[0];
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        vector<vector<int>>vt;
        while(!q.empty()){
            TreeNode* cur = q.front().first;
            int level = q.front().second.first;
            int pos = q.front().second.second;
            q.pop();
            vt.push_back({level,pos,cur->val});
            if(cur->left) q.push({cur->left,{level-1,pos+1}});
            if(cur->right) q.push({cur->right,{level+1,pos+1}});
        }
        sort(vt.begin(),vt.end(),comp);
        for(auto it:vt){
            cout << it[0] << " " << it[1] << " " << it[2] << endl;
        }
        int curvalue = vt[0][0];  
        vector<int> dum;
        dum.push_back(vt[0][2]);  

        for (int i=1;i<vt.size();i++) {
            if (vt[i][0] ==curvalue) {
                dum.push_back(vt[i][2]);
            } else {
                ans.push_back(dum);
                dum.clear();
                dum.push_back(vt[i][2]);
                curvalue = vt[i][0];
            }
        }

        ans.push_back(dum); 
        return ans;
    }
};