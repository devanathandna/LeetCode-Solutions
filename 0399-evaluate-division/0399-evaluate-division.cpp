class Solution {
public:
    double dfs(string start,string end,unordered_map<string,vector<pair<string,double>>>graph,set<string>&visited,double finalv){
        if(start==end) return finalv;
        visited.insert(start);
        for(auto grap: graph[start]){
            string nextletter = grap.first;
            double weight = grap.second;
            if(visited.find(nextletter)==visited.end()){
            double result = dfs(nextletter,end,graph,visited,finalv*weight);
            if(result!=-1.0) return result; 
            }   
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>graph;
        int i=0;
        for(auto it:equations){
            string u = it[0];
            string v = it[1];
            double value = values[i];
            graph[u].push_back({v,value});
            graph[v].push_back({u,1/value});
            i++;
        }
        vector<double>ans;
        for(auto it:queries){
            string start = it[0];
            string end = it[1];
            set<string>visited;
            if(graph.find(start)==graph.end() || graph.find(end)==graph.end()){
                ans.push_back(-1.0);
            }
            else{
            double distance = dfs(start,end,graph,visited,1.0);
            ans.push_back(distance);
            }
        }
        return ans;     
    }
};