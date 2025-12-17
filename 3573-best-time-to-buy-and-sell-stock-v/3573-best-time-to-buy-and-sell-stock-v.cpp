class Solution {
public:
    long long INF = 1e18;
    long long dp[1005][505][3];
    bool vis[1005][505][3];

    long long func(int i,int unit,int state,vector<int>&prices,int k,int n){
        if(i==n){
            if(state==0) return 0;
            return -INF;
        }

        if(unit==k){
            if(state==0) return 0;
            return -INF;
        }
        if(vis[i][unit][state]) return dp[i][unit][state];
        vis[i][unit][state] = true;

        long long ans = -INF;

        if(state==0){
            ans = max(ans,func(i+1,unit,0,prices,k,n));
            ans = max(ans,-prices[i] + func(i+1,unit,1,prices,k,n));
            ans = max(ans,prices[i] + func(i+1,unit,2,prices,k,n));
        }
        else if(state==1){
            ans = max(ans,func(i+1,unit,1,prices,k,n));
            ans = max(ans,prices[i] + func(i+1,unit+1,0,prices,k,n));
        }
        else{
            ans = max(ans,func(i+1,unit,2,prices,k,n));
            ans = max(ans,-prices[i] + func(i+1,unit+1,0,prices,k,n));
        }

        return dp[i][unit][state] = ans;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        memset(vis,false,sizeof(vis));
        return func(0,0,0,prices,k,n);
        
    }
};