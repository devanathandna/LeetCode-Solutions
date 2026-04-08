class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> mul(n, 1); 
 
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int idx = l; idx <= r; idx += k) {
                mul[idx] = (mul[idx] * v) % MOD;
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            nums[i] = (nums[i] * mul[i]) % MOD;
            result ^= nums[i];
        }
        return result;

    }
};