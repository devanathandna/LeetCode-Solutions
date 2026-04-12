class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>ans(m,0);
        for(auto it:matrix){
            for(int i=0;i<it.size();i++){
                ans[i]+=it[i];
            }
        }
        return ans;
    }
};