class Solution {
public:
    int minTimeToType(string word) {
        int n = word.size();
        unordered_map<char,int>mpp;
        for(char c='a';c<='z';c++){
            mpp[c] = c - 'a';
        }
        int curPos =0;
        int count =0;
        for(int i=0;i<n;i++){
            if(curPos==mpp[word[i]]){
                count+=1;
            }
            else{
                int diff = abs(curPos - mpp[word[i]]);
                count += min(diff, 26 - diff);
                count += 1;
            }
            curPos = mpp[word[i]];
        }
        return count;
    }
};