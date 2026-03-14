class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int m,n;
    int maxM;
    int MOD = 1e9+7;
    int dp[52][52][52];
    int func(int i,int j,int steps){
        if(steps > maxM) return 0;
        if(i >=m || i<0 || j<0 || j >=n) return 1;
        if(dp[i][j][steps]!=-1) return dp[i][j][steps];        

        int ans = 0;
        for(int x =0;x<4;x++){
            int ii = i + dx[x];
            int jj = j + dy[x];
            ans = (ans + func(ii,jj,steps+1)) % MOD;
        }
        return dp[i][j][steps] = ans;
    }
    int findPaths(int mm, int nn, int maxMove, int startRow, int startColumn) {
        m=mm,n=nn,maxM = maxMove;
        memset(dp,-1,sizeof(dp));
        return func(startRow,startColumn,0);
    }
};