class Solution {
public:
    int n;
    int limit;
    int func(int i,vector<vector<int>>& books,vector<int>&dp){
       if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
       int h=0,w=0,ans=INT_MAX;
       for(int j=i;j<n;j++){
        w+=books[j][0];
        if(w>limit) break;
        h = max(h,books[j][1]);
        ans = min(ans,h+func(j+1,books,dp));
       }
       return dp[i] =ans;

    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        limit = shelfWidth;
        vector<int>dp(n,-1);
        return func(0,books,dp);

    }
};