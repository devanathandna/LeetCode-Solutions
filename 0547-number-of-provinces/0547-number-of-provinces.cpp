class Solution {
public:
    int n;
    vector<int>parent;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a,int b){
        int u_a = find(a);
        int u_b = find(b);

        if(u_a!=u_b){
            parent[u_b] = u_a;
        } 
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        parent.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        
        for(int i =0;i<n;i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    unite(i,j);
                }
            }
        }

        for(int i:parent){
            cout << i << " ";
        }

        set<int>st(parent.begin(),parent.end());
        return st.size();
        

    }
};