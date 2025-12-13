class Solution {
public:
    bool func(string& cod, const string& b) {
        if(cod.empty()) return false;
        for (char c : cod) {
            if (!isalnum(c) && c!='_') return false;
        }

        if (b != "electronics" && b != "grocery" &&
            b != "pharmacy" && b != "restaurant")
            return false;

        return true;
    }

    bool static comp(pair<string,string>&a,pair<string,string>&b){
        if(a.second == b.second){
            return a.first < b.first;
        }

        return a.second < b.second;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<pair<string,string>>st;
        for(int i=0;i<n;i++){
            if(func(code[i],businessLine[i]) && isActive[i]){
                st.push_back({code[i],businessLine[i]});
            }
        }

        sort(st.begin(),st.end(),comp);
        vector<string>ans;
        for(auto it:st){
            ans.push_back(it.first);
        }

        return ans;
    }
};