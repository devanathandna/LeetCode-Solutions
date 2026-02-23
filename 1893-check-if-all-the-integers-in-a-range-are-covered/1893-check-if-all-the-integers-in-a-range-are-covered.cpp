class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int line[52] = {0};
        for(auto &r:ranges){
            line[r[0]]+=1;
            line[r[1]+1]-=1;
        }
        int count=0;
        for(int i=1;i<=right;i++){
            count+=line[i];
            if(i>=left && count==0) return false;
        }
        return true;
    }
};