class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return {-1,-1};
        int a = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        if(a>=n || nums[a]!=target)  return {-1,-1};
        int m = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        return {a,m-1};
    }
};