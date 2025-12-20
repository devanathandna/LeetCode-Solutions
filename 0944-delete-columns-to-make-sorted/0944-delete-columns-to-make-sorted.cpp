class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        vector<string>ans;
        int m = strs[0].size();
        for(int j=0;j<m;j++){
            string temp = "";
            for(int i=0;i<n;i++){
                temp+=strs[i][j];
            }
            ans.push_back(temp);
        }

        int count=0;
        for(string s:ans){
            for(int i=1;i<s.size();i++){
                if(s[i-1] > s[i]){
                    count++;
                    break;
    
                }
            }
        }

        return count;
    }
};