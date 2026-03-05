class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        int total = 0;
        int pref = 0;
        sort(satisfaction.begin(),satisfaction.end());
        for(int i=n-1;i>=0;i--){
            if(satisfaction[i]+pref >0){
                pref+=satisfaction[i];
                total+=pref;
            }
        }
        return total;
    }
};