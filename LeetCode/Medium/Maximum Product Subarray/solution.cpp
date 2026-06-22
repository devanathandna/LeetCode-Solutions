class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pref = 1;
        int suff = 1;
        int ans = nums[0] , maxi = ans , mini = ans;
        for(int i=1;i<n;i++){
            if(nums[i] < 0) swap(mini,maxi);
            mini = min(nums[i],nums[i]*mini);
            maxi = max(nums[i],nums[i]*maxi);
            ans = max({ans,maxi,mini});
        }
        return ans;
    }
};