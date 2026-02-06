class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n+1);
        int m = edges.size();
        int i=0;
        for(auto &it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back({v,succProb[i]});
            adj[v].push_back({u,succProb[i]});
            i++;
        }
        vector<double>best(n,0.0);
        priority_queue<pair<double,int>>pq;
        best[start_node] = 1.0;

        pq.push({1.0,start_node});
        while(!pq.empty()){
            auto [c,u] = pq.top();
            pq.pop();
            if(c < best[u]) continue;
            if(u == end_node) return c;

            for(auto [v ,cc] : adj[u]){
                if(best[v] < cc*c){
                    best[v] = cc*c;
                    pq.push({best[v],v});
                }
                
            }
        }

        return 0;

    }
};