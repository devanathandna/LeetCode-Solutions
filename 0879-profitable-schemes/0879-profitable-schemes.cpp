class Solution {
public:
int MOD = 1e9+ 7;
int dp[105][105][105];
int minp;
int m;
    int func(int i,int people_used,int profit_gained,vector<int>&group,vector<int>&profit){
        if(i==group.size()){
            return profit_gained >=minp ? 1:0;
        }

        if(dp[i][people_used][profit_gained]!=-1) return dp[i][people_used][profit_gained];

        long long ans = 0;
        ans+= func(i+1,people_used,profit_gained,group,profit);

        if(people_used + group[i] <=m){
            int newProfit = min(minp, profit_gained + profit[i]);
            ans+=func(i+1,people_used+group[i],newProfit,group,profit);
        }
        return dp[i][people_used][profit_gained] = ans % MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        m=n;
        minp = minProfit;
        return func(0,0,0,group,profit);
    }
};