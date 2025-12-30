class Solution {
public:
   bool isMagic(vector<vector<int>> & grid,int x,int y){
    set<int>myset;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int num = grid[x+i][y+j];
            if(num < 1 || num > 9 || myset.count(num)){
                return false;
            }
            myset.insert(num);
        }
    }
    if((grid[x][y] + grid[x][y+1] + grid[x][y+2])!=15) return false;
    if((grid[x+1][y] + grid[x+1][y+1] + grid[x+1][y+2])!=15) return false;
    if((grid[x+2][y] + grid[x+2][y+1] + grid[x+2][y+2])!=15) return false;

    if((grid[x][y] + grid[x+1][y] + grid[x+2][y])!=15) return false;
    if((grid[x][y+1] + grid[x+1][y+1] + grid[x+2][y+1])!=15) return false;
    if((grid[x][y+2] + grid[x+1][y+2] + grid[x+2][y+2])!=15) return false;

    if((grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2])!=15) return false;
    if((grid[x][y+2] + grid[x+1][y+1] + grid[x+2][y])!=15) return false;


    return true;

   }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int gridcount =0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                if(isMagic(grid,i,j)){
                    gridcount++;
                }
            }
        }
        return gridcount;
    }
};