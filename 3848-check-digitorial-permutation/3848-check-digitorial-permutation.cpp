class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<long long>arr(10,1);
        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 2;
        for(int i=3;i<10;i++){
            arr[i] = i*arr[i-1];
        }
        int m = n;
        long long total=0;
        while(m>0){
            int rem = m%10;
            total+=arr[rem];
            m/=10;
        }
        vector<int>mpp1(10,0);
        vector<int>mpp2(10,0);
        long long temp = total;
        while(temp>0){
            int r = temp%10;
            mpp1[r]++;
            temp/=10;
        }
        temp = (long long)n;
        while(temp>0){
            int r = temp%10;
            mpp2[r]++;
            temp/=10;
        }
        for(int i=0;i<10;i++){
            if(mpp1[i]!=mpp2[i]) return false;
        }
        return true;
    }
};