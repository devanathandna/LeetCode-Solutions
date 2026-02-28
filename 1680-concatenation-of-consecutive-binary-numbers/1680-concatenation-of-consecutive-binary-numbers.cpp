class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9+7;
        int bits=0;
        long long res=0;
        for(int i=1;i<=n;i++){
            if((i & (i-1))==0) bits++;
            res= ((res << bits) | i) % MOD;
        }
        return res;
    }
};