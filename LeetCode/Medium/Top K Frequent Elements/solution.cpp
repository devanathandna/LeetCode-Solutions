class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int i:nums){
            mpp[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});

            if(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            int a = pq.top().second;
            ans.push_back(a);
            pq.pop();
        }
        return ans;

        

    }
};