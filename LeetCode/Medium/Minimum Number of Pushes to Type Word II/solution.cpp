class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mpp;
        vector<int>freq;
        for(char c: word){
            mpp[c]++;
        }
        for(auto const& i : mpp){
            freq.push_back(i.second);
        }
        sort(freq.begin(),freq.end(),greater<int>());

        int ans=0;
        int pos=0;
        for(auto const & p : freq){
            pos++;
            if(pos<=8){
                ans+=1*p;
            }
            else if(pos <=16){
                ans+=2*p;
            }
            else if(pos <=24){
                ans+=3*p;
            }
            else{
                ans+=4*p;
            }
        }
        return ans;
    }
};