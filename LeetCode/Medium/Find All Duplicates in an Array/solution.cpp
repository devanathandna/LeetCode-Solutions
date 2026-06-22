class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        vector<int>ans;
        while(i<n){
            int index = nums[i] -1;

            if(nums[index]!=nums[i]){
                swap(nums[index],nums[i]);
            }
            else{
                i++;
            }
        }
        for(int i=0;i<n;i++){
            if(i!=nums[i]-1){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};