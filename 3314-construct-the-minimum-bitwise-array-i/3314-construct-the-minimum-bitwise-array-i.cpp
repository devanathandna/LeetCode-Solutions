class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>res;
        for(int i:nums){
            if((i&1)==0){
                res.push_back(-1);
                continue;
            }

            int x = i;
            int bit =1;
            while(x & bit){
                bit<<=1;
            }
            x^=bit>>1;
            res.push_back(x);

        }
        return res;
    }
};