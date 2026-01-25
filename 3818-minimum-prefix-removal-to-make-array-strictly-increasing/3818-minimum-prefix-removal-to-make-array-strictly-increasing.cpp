class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size()-1;
        while(n>0 && nums[n-1] < nums[n]){
            n--;
        }
        return n;
    }
};