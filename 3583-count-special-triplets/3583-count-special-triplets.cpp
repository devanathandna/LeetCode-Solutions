class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        int MOD = 1e9+7;
        unordered_map<int,int>fro,bac;
        for(int i:nums){
            fro[i]++;
        }
        long long count=0;
        for(int i=0;i<n;i++){
            fro[nums[i]]--;
            bac[nums[i]]++;
            //cout 
            int target = nums[i]*2; 
            if(nums[i]!=0){
                count+= (fro[target]*(bac[target]));
            }
            else{
                long long ans = (long long)fro[target] *(bac[target]-1);
                count+= ans %MOD;
            }
        }

        return count%MOD;
    }
};