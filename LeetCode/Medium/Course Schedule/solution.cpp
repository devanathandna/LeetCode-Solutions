class Solution {
public:
vector<int>topo;
vector<int>indegree;
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>>adj(numCourses);
        indegree.resize(numCourses,0);
        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();q.pop();
            topo.push_back(u);
            for(int i:adj[u]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        return topo.size() == numCourses;
    }
};