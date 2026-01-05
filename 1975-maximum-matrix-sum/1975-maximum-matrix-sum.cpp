class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long total= 0;
        vector<int>res;
        for (auto &row: matrix) {
            for (int i: row) {
                int val = abs(i);        
                total+=val;
                res.push_back(val);        
            }
        }

        sort(res.begin(),res.end());
        int negCount= 0;
        for (auto &row :matrix) {
            for (int i: row) {
                if (i<0)negCount++;
            }
        }

        if (negCount%2!=0) {
            return total -2LL*res[0];
        }

        return total;
    }
};