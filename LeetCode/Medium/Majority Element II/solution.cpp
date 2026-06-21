class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i:nums){
            mpp[i]++;
        }
        int target = nums.size()/3;
        vector<int>ans;
        for(auto it:mpp){
            if(it.second > target){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};