class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({arr[i],i});
        }
        int count = 1;
        int prev = INT_MIN;
        while(!pq.empty()){
            int val = pq.top().first;
            if(prev==val){
                ans[pq.top().second] = count;
            }
            else if(prev!=INT_MIN && val > prev){
                count++;
                ans[pq.top().second] = count;
                prev = val;
            }
            if(prev==INT_MIN){
                prev = val;
                ans[pq.top().second] = count;
            }
            pq.pop();
        }
        return ans;

    }
};