class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int neednum = target-num;
            if(mpp.find(neednum)!=mpp.end()){
                return {mpp[neednum],i};
            }
            mpp[nums[i]] = i;
        }
        return {-1,-1};
    }
};