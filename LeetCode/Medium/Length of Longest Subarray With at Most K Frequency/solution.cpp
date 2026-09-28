class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
     int n= nums.size();
     unordered_map<int,int>mpp;
     int l=0;
     int maxlen = 0;
     for(int right=0;right<n;right++){
        mpp[nums[right]]++;
        while(mpp[nums[right]] > k){
            mpp[nums[l]]--;
            l++;
        }
        maxlen = max(maxlen,right-l+1);
     }   
     return maxlen;
    }
};