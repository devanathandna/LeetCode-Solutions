class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 0);
    }

    int findp(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = findp(parent[x]);
    }

    void findr(int u, int v) {
        int ul = findp(u);
        int vl = findp(v);

        if (ul == vl) return;

        if (rank[ul] > rank[vl]) {
            parent[vl] = ul;
        }
        else if (rank[ul] < rank[vl]) {
            parent[ul] = vl;
        }
        else {
            parent[vl] = ul;
            rank[ul]++;
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        DSU dsu(n);
        unordered_map<int, vector<int>> adj;

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            dsu.findr(e[0], e[1]);
        }

        unordered_map<int, vector<int>> comp;

        for (int i = 0; i < n; i++) {
            comp[dsu.findp(i)].push_back(i);
        }

        int count = 0;

        for (auto &it : comp) {
            vector<int> &nodes = it.second;
            int sz = nodes.size();

            bool ok = true;

            for (int node : nodes) {
                if (adj[node].size() != sz - 1) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                count++;
        }

        return count;
    }
};