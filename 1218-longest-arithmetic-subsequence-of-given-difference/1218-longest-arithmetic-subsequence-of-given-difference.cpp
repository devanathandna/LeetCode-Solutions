class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int diff = difference;
        unordered_map<int,int>mpp;
        int ans = 0;
        for(int x:arr){
            mpp[x] = mpp[x-diff]+1;
            ans = max(ans,mpp[x]);
        }
        return ans;
    }
};