class Solution {
public:
    const int dx[4] = {-1,0,1,0};
    const int dy[4] = {0,1,0,-1};
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && visited[i][j]!=1){
                    count++;
                    q.push({i,j});
                    while(!q.empty()){
                        auto [ii,jj] = q.front();q.pop();
                        for(int k=0;k<4;k++){
                            int x = ii + dx[k];
                            int y = jj + dy[k];
                            if(x>=0 && y>=0 && x<n && y <m && visited[x][y]==0 && grid[x][y]=='1'){
                                visited[x][y] = 1;
                                q.push({x,y});
                            }
                        }
                    }
                }
            }
        }
        return count;

    }
};