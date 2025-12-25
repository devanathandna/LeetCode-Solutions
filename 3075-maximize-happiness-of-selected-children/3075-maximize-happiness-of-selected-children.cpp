class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        priority_queue<int>pq;
        for(int i:happiness){
            pq.push(i);
        }
        int counter=0;
        long long ans=0;
        while(!pq.empty() && k--){
            int p = pq.top();pq.pop();
            int a = p-counter;
            if(a>=0) ans+=a;
            
            counter++;
        }
        return ans;
    }
};