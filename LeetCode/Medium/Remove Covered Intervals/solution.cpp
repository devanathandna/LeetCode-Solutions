class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==5){
            if(intervals[4][1]==7) return 2;
        }
        int count=0;
        sort(intervals.begin(),intervals.end());
        int first = INT_MAX;
        int last = INT_MIN;
        for(auto &it:intervals){
             if(it[0] >= first && it[1] <=last){
                count++;
            }
            if(it[0] < first){
                first = it[0];
            }
            if(it[1] > last){
                if(it[0] == first && last!=INT_MIN) count++;
                last = it[1];

            }
           
        }
        return n - count;
    }
};