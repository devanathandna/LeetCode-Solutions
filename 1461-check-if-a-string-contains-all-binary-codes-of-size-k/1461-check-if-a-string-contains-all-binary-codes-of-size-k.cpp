class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string>ans;
        int l=0,r=0;
        int n = s.size();
        //string res="";
        for(int i=0;i<=n-k;i++){
            string res="";
            for(int j=i;j<i+k;j++){
                res+=s[j];
            }
            ans.insert(res);
        }
        for(string s:ans){
            cout << s << endl;
        }

        return pow(2,k) == ans.size();
    }
};