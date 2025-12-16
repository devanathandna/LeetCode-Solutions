class Solution {
public:
    static const int MAXN = 161;
    static const int INF = 1e9;

    int n,B;
    vector<int>children[MAXN];
    int profit[MAXN][2];

    vector<int>dp[MAXN][2][2];
    bool visited[MAXN][2][2];

    void buildTree(const vector<vector<int>>&hierarchy){
        for(int i=0;i<n;i++){
            children[i].clear();
        }

        for(auto &e:hierarchy){
            int parent = e[0]-1;
            int child = e[1]-1;
            children[parent].push_back(child);
        }
    }
    void dfs(int node,int bossbuy,int buy,const vector<int>&present ){
        if(visited[node][bossbuy][buy]) return;
        visited[node][bossbuy][buy] = true;;

        dp[node][bossbuy][buy].assign(B+1,-INF);

        int cost = 0;
        if(buy ==1){
            if(bossbuy==1){
                cost = present[node]/2;
            }
            else{
                cost = present[node];
            }
        }
        if(cost <=B){
        dp[node][bossbuy][buy][cost] = (buy ? profit[node][bossbuy]:0);
        }

        for (int child : children[node]) {

            dfs(child, buy, 1, present);
            dfs(child, 0,   0, present);

            vector<int> merged(B+1, -INF);

            for (int used=0;used<=B;used++) {
                if (dp[node][bossbuy][buy][used] == -INF) continue;

                for (int take = 0; take + used <= B; take++) {
                    int bestChild =
                        max(dp[child][buy][1][take],
                            dp[child][0][0][take]);

                    if (bestChild == -INF) continue;

                    merged[used + take] =
                        max(merged[used + take],
                            dp[node][bossbuy][buy][used] + bestChild);
                }
            }

            dp[node][bossbuy][buy] = merged;
        }
    }
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        this->n = n;
        this->B = budget;

        memset(visited, false, sizeof(visited));

        for (int i=0;i<n;i++) {
            profit[i][0] =future[i] - present[i];
            profit[i][1] =future[i] - present[i] / 2;
        }

        buildTree(hierarchy);
        dfs(0, 0, 0, present);
        dfs(0, 0, 1, present);

        int ans = 0;
        for (int b=0;b<=B;b++) {
            ans = max(ans,dp[0][0][0][b]);
            ans = max(ans,dp[0][0][1][b]);
        }
        return ans;
    }
};