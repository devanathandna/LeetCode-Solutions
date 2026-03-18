class Solution {
public:
    int n,m,k,ans=0;
    void func(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& pref){
        if(i>=n || j>=m) return;

        pref[i][j] = grid[i][j];


        if(i>0) pref[i][j] += pref[i-1][j];
        if(j >0) pref[i][j] += pref[i][j-1];

        if(i>0 && j>0) pref[i][j] -= pref[i-1][j-1];

                if(pref[i][j] <=k) ans++;

        func(i,j+1,grid,pref);

        if(j==0) func(i+1,0,grid,pref);
    }
    int countSubmatrices(vector<vector<int>>& grid, int k_) {
        n = grid.size();
        m = grid[0].size();
        k = k_;
        vector<vector<int>>pref(n,vector<int>(m,0));

        func(0,0,grid,pref);

        return ans;

    }
};