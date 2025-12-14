class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();
        long long total = 0;
        int neg = -1;
        for(int i=0;i<n;i++){
            total+=balance[i];
            if(balance[i] < 0) neg = i;
        }
        if(total < 0) return -1;
        if(neg == -1) return 0;

        long long need = -1*balance[neg];
        vector<pair<int,long long>>donors;

        for(int i=0;i<n;i++){
            if(balance[i] > 0){
                int di = min((i-neg+n)%n,(neg-i+n)%n);
                donors.push_back({di,balance[i]});
            }
        }

        sort(donors.begin(),donors.end());
        long long moves = 0;
        for(auto it:donors){
            int dist = it.first;
            long long amt = it.second;

            if(need==0) break;
            long long take = min(need,amt);

            moves+= take*dist;
            need-=take;
        }

        return need == 0 ? moves :-1;
    }
};