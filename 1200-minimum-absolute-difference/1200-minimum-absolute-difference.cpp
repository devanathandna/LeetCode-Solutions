class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>res;
        sort(arr.begin(),arr.end());
        int mini = INT_MAX;
        for(int i=1;i<arr.size();i++){
            int ans = arr[i] - arr[i-1];
            mini = min(mini,abs(ans));
        }

        for(int i=1;i<arr.size();i++){
            vector<int>ans;
            int a = arr[i] - arr[i-1];
            if(a==mini){
                ans.push_back(arr[i-1]);
                ans.push_back(arr[i]);
                res.push_back(ans);
            }
        }

        return res;
    }
};