class Solution {
public:
    int func(int n,vector<int>&dp){
        if(n<0) return 0;
        if(n==0) return 0;
        int ans = n;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i*i<=n;i++){
            ans = min(ans,1+func(n-i*i,dp));
        }

        return dp[n] = ans;
    }
    int numSquares(int n) {
        if(n<3) return n;
        int a = sqrt(n);
        if(a*a==n) return 1;
        vector<int>dp(n+1,-1);
        int ans = func(n,dp);
        return ans;
    }
};