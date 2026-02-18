class Solution {
public:
    bool hasAlternatingBits(int n) {
        int start = -1;
        while(n>0){
            int r = n%2;
            
            if(start==r) return false;
            start=r;
            n=n/2;
        }
        return true;
    }
};