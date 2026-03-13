class Solution {
public:
    long long can(long long mid, vector<int>&w){
        long long sum = 0;
        for(int &x:w){
            long long k = 2*mid/x;

            long long a = (sqrt(1+4*k)-1)/2;
            sum+=a;
        }
        return sum;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 0,r = 1e18;
        long long ans = 0;
        while(l<=r){
            long long mid = l + (r-l)/2;
            if(can(mid,workerTimes)>= mountainHeight){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }   
        return ans;
    }
};