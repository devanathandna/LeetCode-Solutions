class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int pref =0;
        int count=0;
        for(int i:nums){
            pref+=i;
            int find = pref-k;
            count+=mpp[find];
            mpp[pref]++;
        }
        return count;
    }
};