class Solution {
public:
    int func(int i,bool firstTaken,vector<int>&nums,vector<vector<int>>&dp){
        if(i>=nums.size()) return 0;
        if(i==nums.size()-1){
            return firstTaken? 0 : nums[i];
        }

        if(dp[i][firstTaken]!=-1) return dp[i][firstTaken];
        int take = 0;
        int nottake = 0;
        bool newFirst = firstTaken || (i == 0);
        take = nums[i] + func(i + 2, newFirst, nums,dp);

        nottake = func(i + 1, firstTaken, nums,dp);

        return dp[i][firstTaken] = max(nottake,take);


    }
    int rob(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(2,-1));
        return func(0,false,nums,dp);
    }
};