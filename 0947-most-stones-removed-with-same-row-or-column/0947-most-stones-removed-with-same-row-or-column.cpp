class Solution {
public:
    void dfs(int idx,vector<vector<int>>&stones,unordered_map<int,vector<int>>&rows,unordered_map<int,vector<int>>&cols,vector<bool>&visited){
        visited[idx] = true;

        int x = stones[idx][0];
        int y = stones[idx][1];

        for(int n :rows[x]){
            if(!visited[n]){
                dfs(n,stones,rows,cols,visited);
            }
        }

        for(int n:cols[y]){
            if(!visited[n]){
                dfs(n,stones,rows,cols,visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int,vector<int>>rows,cols;
        for(int i=0;i<n;i++){
            rows[stones[i][0]].push_back(i);
            cols[stones[i][1]].push_back(i);
        }

        vector<bool>visited(n,false);
        int components = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                components++;
                dfs(i,stones,rows,cols,visited);
            }
        }
        return n -components;
    }
};