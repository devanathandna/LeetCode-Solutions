class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s[0]=='0') return false;
        bool zeroes = false;
        for(int i=1;i<s.size();i++){
            if(s[i]=='0'){
                zeroes = true;
            }
            if(s[i]=='1' && zeroes) return false;
        }
        return true;
    }
};