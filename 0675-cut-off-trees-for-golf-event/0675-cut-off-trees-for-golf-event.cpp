class Solution {
public:
    int n,m;
    const int dx[4] = {-1,0,1,0};
    const int dy[4] = {0,1,0,-1};

    int bfs(vector<vector<int>>& forest,int sx,int sy,int tx,int ty){
        if(sx==tx && sy==ty) return 0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        visited[sx][sy] =1;
        queue<pair<int,int>>q;
        q.push({sx,sy});
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            steps++;
            while(sz--){
            auto [i,j] = q.front();q.pop();
            for(int k=0;k<4;k++){
                int x = i + dx[k];
                int y = j + dy[k];

                if(x==tx && y == ty) return steps;
                if(x>=0 && x<n && y>=0 && y<m && visited[x][y]!=1 && forest[x][y] >0){
                    visited[x][y] = 1;
                    q.push({x,y});
                }
            }

            }
        }

        return -1;
    
    }


    int cutOffTree(vector<vector<int>>& forest) {
        n = forest.size();
        m = forest[0].size();
        if(forest[0][0]==0) return -1;
        vector<array<int,3>>arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j] > 0){
                    arr.push_back({forest[i][j],i,j});
                }
            }
        }

        sort(arr.begin(),arr.end());
        int sx=0,sy=0;
        int totalsteps=0;

        for(auto &t:arr){
            int tx = t[1];
            int ty = t[2];

            int dist = bfs(forest,sx,sy,tx,ty);
            if(dist == -1) return -1;
            totalsteps+=dist;

            sx = tx,sy=ty;
        }

        return totalsteps;
    }
};