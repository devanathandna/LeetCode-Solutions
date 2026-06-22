class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        unordered_map<char,int>mpp;
        for(char c:text){
            mpp[c]++;
        }
        
        int maxi = INT_MAX;
        string s = "balon";
        for(char c:s){
            if(c=='l') maxi = min(maxi,mpp[c]/2);
            else if(c=='o') maxi = min(maxi,mpp[c]/2);
            else maxi = min(maxi,mpp[c]);

            cout << c << " " << mpp[c];
        }
        return maxi<0 ? 0 : maxi;
    }
};