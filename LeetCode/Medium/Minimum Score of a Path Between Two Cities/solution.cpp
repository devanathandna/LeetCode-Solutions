class Solution {
public:
    vector<int>parent;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n+1);
        iota(parent.begin(),parent.end(),0);

        for(auto &it:roads){
            parent[find(it[0])] = find(it[1]);
        }

        int res = INT_MAX;
        for(auto &it:roads){
            if(find(parent[it[0]]) == find(1)){
                res = min(res,it[2]);
            }
        }
        return res;

    }
};