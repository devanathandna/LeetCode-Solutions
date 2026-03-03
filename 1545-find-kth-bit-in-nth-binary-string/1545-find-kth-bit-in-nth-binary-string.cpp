class Solution {
public:
    string invert(string s){
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                s[i] = '1';
            }
            else{
                s[i] = '0';
            }
        }
        return s;
    }
    char findKthBit(int n, int k) {
        vector<string>res(21,"0");
        res[1] = "011";
        for(int i=2;i<=n;i++){
            string re = invert(res[i-1]);
            reverse(re.begin(),re.end());
            res[i] = res[i-1] + "1" + re;
        }
        string ans = res[n-1];
        cout << ans << endl;
        return ans[k-1];
    }
};