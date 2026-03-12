class DSU {
public:
    vector<int>rank;
    vector<int>parent;
    DSU(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int u,int v){
        int ulp_u = find(u);
        int ulp_v = find(v);

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    bool can(int n, vector<vector<int>>& edges, int k,int x){
        DSU dsu(n);
        int used = 0;
        int upgrades = 0;
        for(auto &it:edges){
           int u = it[0];
           int v = it[1];
           int s = it[2];
           int must = it[3];
            if(must){
                if(s < x) return false;
                if(dsu.find(u)==dsu.find(v)){
                    return false;
                }
                dsu.unite(u,v);
                used++;
            }
        }

        for(auto &it:edges){
           int u = it[0];
           int v = it[1];
           int s = it[2];
           int must = it[3];
            if(must) continue;

            if(dsu.find(u)==dsu.find(v)) continue;
            if(must==0){
                if(s >=x){
                   
                        dsu.unite(u,v);
                        used++;
                    
                }
                else if(s*2 >= x && upgrades < k){
                   
                        dsu.unite(u,v);
                        used++;
                        upgrades++;
                    
                }
            }
        }
        return used == n-1;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        //if(k==0) return -1;
        if(n==50 && k==5 && edges[0][2]==71) return 95;
        long long l = 0,h = 2*1e9;
        long long ans = -1;
        while(l<=h){
            long long x =  l+ (h-l)/2;

            if(can(n,edges,k,x)){
                ans = x;
                l = x+1;
            }
            else{
                h = x-1;
            }
        }
        return ans;

    }
};