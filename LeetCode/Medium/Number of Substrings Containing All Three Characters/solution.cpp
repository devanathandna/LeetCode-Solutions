class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l=0,r=0;
        vector<int>ans(3,0);
        int count=0;
        while(r<n){
            if(s[r]=='a'){
                ans[s[r]-'a']++;
            }
            if(s[r]=='b'){
                ans[s[r]-'a']++;
            }
            if(s[r]=='c'){
                ans[s[r]-'a']++;
            }

            while(ans[0]!=0 && ans[1]!=0 && ans[2]!=0){
               
                ans[s[l]-'a']--;
                l++;
            }
            count+=l;
            r++;
            
        }
        return count;
    }
};