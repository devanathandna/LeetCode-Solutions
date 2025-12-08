class Solution {
public:
    int countTriples(int n) {
        int count = 0;


        for(int i=2;i<=n;i++){
            for(int j=2;j<=n;j++){
                int squared = i*i + j*j;
                int sqr = sqrt(squared);
                if(sqr*sqr == squared && sqr <=n){
                    count++;
                }
            }
        }
        return count;
    }
};