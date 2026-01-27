class Solution {
public:
    vector<vector<pair<int,int>>>adj;
    int func(int n){
        vector<bool>vis(n,false);
        vector<int>dist(n,1e9);

        priority_queue<pair<int,int>>q;
        q.push({0,0});
        dist[0] = 0;
        while(!q.empty()){
            int u = q.top().second;
            q.pop();
            if(vis[u]) continue;
            vis[u] = true;
            for(auto [v,w] : adj[u]){
                if(dist[u]+w < dist[v]){
                    dist[v] = dist[u] + w;
                    q.push({-dist[v],v});
                }
            }
        }

        if(dist[n-1] == 1e9) return -1;
        return dist[n-1];
    }
    int minCost(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],2*it[2]});
        }

        return func(n);
    }
};