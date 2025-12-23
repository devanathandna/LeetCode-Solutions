class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<pair<long long,pair<int,int>>>sweep;
        for(auto &e:events){
            sweep.push_back({e[0],{1,e[2]}});
            sweep.push_back({e[1],{0,e[2]}});
        } 
        sort(sweep.begin(),sweep.end(),[](auto &a, auto &b) {
            if (a.first!=b.first) return a.first< b.first;
            return a.second.first >b.second.first;
        });

        int best = 0;
        int ans = 0;
        for(auto &p:sweep){
            int x = p.second.first;
            int y = p.second.second;

            if(x==0){
                best = max(best,y);
            }
            else{
                ans = max(ans,best+y);
            }
        }
        return ans;

        
    }
};