class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mpp;
        vector<int>freq;
        for(char c:word){
            mpp[c]++;
        }
        for(auto &it:mpp){
            freq.push_back(it.second);
        }
        sort(freq.begin(),freq.end(),greater<>());
        int ans =0 ,pos=0;
        for(int i:freq){
            pos++;
            if(pos <=8){
                ans+=i;
            }
            else if(pos <=16){
                ans+=(2*i);
            }
            else if(pos <=24){
                ans+=(3*i);
            }
            else{
                ans+=(4*i);
            }
        }
        return ans;
    }
};