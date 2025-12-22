class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        vector<int>mp(26,0);
        for(char i:tasks){
            mp[i-'A']++;
        }
        for(int i=0;i<26;i++){
            if(mp[i]){
                pq.push(mp[i]);
            }
        }
        int count=0;
        while(!pq.empty()){
            vector<int>remain;
            int cycle = n+1;

            while(cycle and !pq.empty()){
                int max_freq = pq.top();
                pq.pop();
                if(max_freq >1){
                    remain.push_back(max_freq-1);
                }
                ++count;
                --cycle;

            }

            for(int c:remain){
                pq.push(c);
            }
            if(pq.empty()) break;
            count+=cycle;
        }
        return count;
    }
};