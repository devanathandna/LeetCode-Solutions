class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n>0){
            int a = n%2;
            if(a==1) count++;
            n/=2;
        }
        return count;
    }
};