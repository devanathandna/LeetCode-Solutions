class Solution {
public:
    int n,m;
    int func(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(i>=n || i< 0 || j >=m || j<0) return INT_MAX;

        if(i==n-1) return matrix[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];

        int left = func(i+1,j-1,matrix,dp);
        int right = func(i+1,j+1,matrix,dp);
        int dia = func(i+1,j,matrix,dp);

        return dp[i][j] = min({left,right,dia})+ matrix[i][j];

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n  = matrix.size();
        m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(mini,func(0,i,matrix,dp));
        }
        return mini;
    }
};