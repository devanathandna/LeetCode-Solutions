class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for(int x = left;x<=right;x++){
            bool c = false;
            for(auto it:ranges){
                if(x>=it[0] && x<=it[1]){
                    c = true;
                    break;
                }
            }
            if(!c) return false;
        }
        return true;
    }
};