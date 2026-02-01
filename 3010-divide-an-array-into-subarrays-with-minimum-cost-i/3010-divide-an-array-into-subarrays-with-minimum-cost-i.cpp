class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        sum+=nums[0];
        int mini1 = INT_MAX;
        int mini_i = 1;
        for(int i=n-1;i>=1;i--){
            if(mini1 > nums[i]){
                mini1 = nums[i];
                mini_i = i;
            }
        }
        int mini2 = INT_MAX;
        for(int i=1;i<n;i++){
            if(mini2 > nums[i] && i!=mini_i){
                mini2 = nums[i];
            }
        }

        sum+= mini1+mini2;
        return sum;
    }
};