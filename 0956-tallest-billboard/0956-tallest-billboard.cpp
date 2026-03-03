class Solution {
public:
    int n;
    vector<int>rods;
    unordered_map<int,unordered_map<int,int>>memo;
    int solve(int i,int diff){
        if(i==n){
            if(diff == 0) return 0;
            return -1e9;
        }
        if(memo[i].count(diff)) return memo[i][diff];

        int r = rods[i];
        int skip = solve(i+1,diff);

        int addT = solve(i+1,diff+r);
        int addS;
        if(r<=diff){
            addS = solve(i+1,diff-r)+r;
        }
        else{
            addS = solve(i+1,r-diff)+diff;
        }
        int ans = max({skip,addT,addS});

        return memo[i][diff] = ans;
    }
    int tallestBillboard(vector<int>& rodsT) {
        rods = rodsT;
        n = rods.size();
        return max(0,solve(0,0));
    }
};