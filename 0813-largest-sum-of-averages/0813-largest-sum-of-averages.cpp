class Solution {
public:
int n;
    double func(int i,int k,vector<int>&nums,vector<vector<double>>&dp){
        if(i==n) return 0;
        if(k<=0) return -1e9;

        if(dp[i][k]!=-1) return dp[i][k];

        double sum = 0 ,ans = 0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            double avg = sum/(j-i+1);
            ans = max(ans,avg+func(j+1,k-1,nums,dp));
        }
        return dp[i][k] = ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        n = nums.size();
        vector<vector<double>>dp(n,vector<double>(k+1,-1));
        return func(0,k,nums,dp);
    }
};