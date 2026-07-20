class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        if(k==0) return grid;
        
        
        for(int a=0;a<k;a++){
            vector<vector<int>>ans(n,vector<int>(m,0));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(i==n-1 && j==m-1){
                        ans[0][0] = grid[n-1][m-1];
                    }
                    else if(j==m-1){
                        ans[(i+1)%n][0] = grid[i][m-1];
                    }
                    else{
                        ans[i][(j+1)%m] = grid[i][j];
                    }
                }
            }
            grid = ans;
        }
        return grid;

    }
};