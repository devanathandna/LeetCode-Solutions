class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res="";
        for(string &s:words){
            int ans =0;
            for(int i=0;i<s.size();i++){
                ans+=weights[s[i]-'a'];
            }
            
            ans=ans%26;
            cout << ans << endl;
            int index = 26-ans-1;
            res+=('a'+index);
        }

        return res;
        
    }
};