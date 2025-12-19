const int DX[] = {-1,0,1,0};
const int DY[] = {0,1,0,-1};

class Solution {
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        //visited[sr][sc] = 1;
        int oldcolor = image[sr][sc];
        image[sr][sc] = color;
        q.push({sr,sc});
        while(!q.empty()){
            int ii = q.front().first;
            int jj = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x = ii + DX[i];
                int y = jj + DY[i];

                if(x>=0 && x < n && y>=0 && y<m && visited[x][y]==0 && image[x][y]==oldcolor){
                    image[x][y] = color;
                    visited[x][y] = 1;
                    q.push({x,y});
                }
            }
        }
        return image;
    }
};