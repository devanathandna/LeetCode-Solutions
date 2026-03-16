class Solution {
public:
int r[8] = {2,2,1,1,-2,-2,-1,-1};
int c[8] = {1,-1,2,-2,1,-1,-2,2};
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1.0)));
        return func(row,column,k,dp,n);
    }
    double func(int i,int j,int k,vector<vector<vector<double>>>&dp,int n){
        if(i < 0 || i>=n || j<0 || j>=n) return 0;

        if(k==0) return 1.0;
        if(dp[i][j][k]!=-1.0) return dp[i][j][k];

        double ans = 0.0;
        for(int x=0;x<8;x++){
            ans+=func(i+r[x],j+c[x],k-1,dp,n);
        }

        ans/=8.0;

        return dp[i][j][k] = ans;
    }
};