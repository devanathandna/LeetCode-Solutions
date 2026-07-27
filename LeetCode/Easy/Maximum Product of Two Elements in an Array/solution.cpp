class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = INT_MIN,second = INT_MIN;
        int ind  =-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > first){
                first = nums[i];
                ind  = i;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] > second && i!=ind){
                second = nums[i];
            }
        }

        return (second-1)*(first-1);
    }
};