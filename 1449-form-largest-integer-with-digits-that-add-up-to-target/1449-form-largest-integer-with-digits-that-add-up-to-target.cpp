class Solution {
public:
    vector<int> cost;
    vector<int> dp;

    int solve(int t) {
        if (t == 0) return 0;
        if (t < 0) return -1;
        if (dp[t] != -2) return dp[t];

        int best = -1;
        for (int d = 0; d < 9; d++) {
            int prev = solve(t - cost[d]);
            if (prev != -1) {
                best = max(best, prev + 1);
            }
        }
        return dp[t] = best;
    }

    string largestNumber(vector<int>& cost_, int target) {
        cost = cost_;
        dp.assign(target + 1, -2);

        if (solve(target) <= 0) return "0";
        string ans;
        int t = target;

        for (int d = 8; d >= 0; d--) {
            while (t >= cost[d] &&
                   solve(t) == solve(t - cost[d]) + 1) {
                ans.push_back('0' + (d + 1));
                t -= cost[d];
            }
        }
        return ans;
    }
};
