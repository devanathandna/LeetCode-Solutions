class Solution {
public:
int MOD = 1e9+7;
    int fact(int n){
        long long product = 1;
        for(int i=1;i<=n;i++){
            product*=i;
        }
        return product %MOD;
    }
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        for(int i=1;i<n;i++){
            if(complexity[0] >= complexity[i]){
                return 0;
            }
        }

        int val = fact(n-1);
        return val;

    }
};