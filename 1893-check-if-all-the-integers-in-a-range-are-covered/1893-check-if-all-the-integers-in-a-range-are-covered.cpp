class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        bool flag = true;
        for(auto it:ranges){
            int v = it[0];
            int u = it[1];
            if(v < left && u < left) flag = false;
            if(v>right && u > right) flag = false;
        }
        return flag;
    }
};