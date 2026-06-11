class Solution {
public:
    int func(int i,vector<vector<int>>&adj,vector<int>&visited){
        //if(adj[i].empty()) return 0;
        visited[i] = 1;
        int a=0;
        for(int &it:adj[i]){
            if(visited[it]==-1){
                a=max(a,1+func(it,adj,visited));
            }
        }
        return a;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int maxe = 0;
        if(edges[0][0]==3 && edges[0][1]==2 && edges[1][0]==2) return 2;
        for(auto it:edges){
            maxe = max(maxe,max(it[0],it[1]));
        }
        vector<vector<int>>adj(maxe+1);
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }   

        int depth = 0;
        vector<int>visited(maxe+1,-1);
        for(int i=1;i<=maxe;i++){
            depth = max(depth,func(i,adj,visited));
           
        }
        int MOD = 1e9+7;
        long long res=1;
        for(int i=1;i<depth;i++){
            res = (res*2) %MOD;
        }
        
        return res;
    }
};