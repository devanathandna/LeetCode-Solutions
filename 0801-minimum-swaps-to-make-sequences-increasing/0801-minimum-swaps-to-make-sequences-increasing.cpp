class Solution {
public:
int n;
    int func(int index,vector<int>& nums1, vector<int>& nums2,int swaped,vector<vector<int>>&dp){
        if(index >= nums1.size()) return 0;
        if(dp[index][swaped]!=-1) return dp[index][swaped];

        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        if(swaped) swap(prev1,prev2);

        int ans = INT_MAX;

        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = min(ans,func(index+1,nums1,nums2,0,dp));
        }

        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans,1+ func(index+1,nums1,nums2,1,dp));
        }

        return dp[index][swaped] = ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        n = nums1.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));

        return func(1,nums1,nums2,0,dp);
    }
};