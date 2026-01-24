class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<vector<int>>adj(n);
        vector<vector<string>>ad(n);

        for(int i=0;i<n;i++){
            for(int v : friends[i]){
                adj[i].push_back(v);
            }
        }
        for(int i=0;i<n;i++){
            for(string cc: watchedVideos[i]){
                ad[i].push_back(cc);
            }
        }

        vector<int>visited(n,0);
        queue<int>q;
        q.push(id);
        visited[id] =1;
        int l=0;
        vector<int>counts;
        while(!q.empty()){
            int r = q.size();
            if(l==level){
                while(r--){
                    counts.push_back(q.front());
                    q.pop();
                }
                break;
            }

            while(r--){
                int u = q.front();q.pop();
                for(int v :adj[u]){
                    if(visited[v]==0){
                        q.push(v);
                        visited[v] = 1;
                    }
                }
            }
            l++;
        }
        
        unordered_map<string,int>mpp;
        for(int i : counts){
    for(string &s : ad[i]){
        mpp[s]++;
    }
}

        vector<pair<string,int>>vect;
        for(auto it:mpp){
            vect.push_back(it);
        }
        sort(vect.begin(),vect.end(),[](auto &a,auto &b){
            if(a.second != b.second) return a.second < b.second;
            return a.first < b.first;
        });

        vector<string>val;
        for(auto &p:vect){
            val.push_back(p.first);
        }

        return val;
    }
};