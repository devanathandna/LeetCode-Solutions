class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int count=0;
        int q = queryTime;
        for(int i=0;i<startTime.size();i++){
            if(startTime[i]<=q && endTime[i] >=q){
                count++;
            }
        }
        return count;
    }
};