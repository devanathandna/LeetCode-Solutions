class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>ans(n-k+1,vector<int>(m-k+1,0));

        for(int i=0;i<=n-k;i++){
            for(int j=0;j<=m-k;j++){

                set<int>st;
                for(int r=i;r<i+k;r++){
                    for(int c=j;c<j+k;c++){
                        st.insert(grid[r][c]);
                    }
                }

                if(st.size()==1){
                    ans[i][j] = 0;
                    continue;
                }

                vector<int>distinct(st.begin(),st.end());
                int minDiff = 1e9;
                for(int x=1;x<distinct.size();x++){
                    int mini = abs(distinct[x] - distinct[x - 1]);
                    minDiff = min(mini,minDiff);
                }
                ans[i][j] = minDiff;
            }
        }
        return ans;
    }
};