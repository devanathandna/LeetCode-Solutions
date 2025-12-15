class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        //int r = 1;
        int cnt =1;
        int len =1;
        for(int r=1;r<n;r++){
            if(prices[r] == prices[r-1]-1){
                len++;
            }
            else{
                len =1;
            }
            cnt+=len;
        }
        return cnt;
    }
};