class Solution {
public:
unordered_map<string,string>parent;
string find(string x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unite(string a,string b){
    string u_a = find(a);
    string u_b = find(b);
    if(u_a!=u_b){
        parent[u_b] = u_a;
    }
}

    vector<vector<string>> accountsMerge(vector<vector<string>>&accounts){
        for(auto &acc :accounts){
            for(int i=1;i<acc.size();i++){
                if(parent.find(acc[i])==parent.end()){
                    parent[acc[i]] = acc[i];
                }
            }
        }


        for(auto &acc: accounts){
            string start = acc[1];
            for(int i=2;i<acc.size();i++){
                unite(start,acc[i]);
            }
        }

        unordered_map<string,vector<string>>mpp;
        for(auto &p:parent){
            string mail = p.first;
            string root = find(mail);
            mpp[root].push_back(mail);
        }

        unordered_map<string,string>emailtoname;
        for(auto &acc :accounts){
            for(int i=1;i<acc.size();i++){
                emailtoname[acc[i]] = acc[0];
            }
        }


        vector<vector<string>>result;
        for(auto &p : mpp){
            vector<string>dum = p.second;
            sort(dum.begin(),dum.end());

            string name;

            name = emailtoname[dum[0]];
                vector<string>res;
                res.push_back(name);
                for(auto &e:dum){
                    res.push_back(e);
                }

                result.push_back(res);
            
        }

        return result;
    }

};