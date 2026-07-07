class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long m = 0;
        int nn = n;
        while(nn>0){
            int rem = nn%10;
            sum+=rem;

            if(rem!=0){
                m = m*10 + rem; 
            }
            nn/=10;
        }
        nn=0;
        while(m>0){
            int r = m%10;
            nn = nn*10+r;
            m/=10;
        }
        
        return nn*sum;
    }
};