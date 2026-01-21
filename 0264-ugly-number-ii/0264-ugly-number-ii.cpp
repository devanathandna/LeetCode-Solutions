class Solution {
public:
    int nthUglyNumber(int n) {
        int un1 =1;
        int un2 =1;
        int un3=1;
        vector<int>arr(n+1);
        arr[1]=1;
        for(int i=2;i<=n;i++){
            int a = arr[un1] *2;
            int b = arr[un2] *3;
            int c = arr[un3] *5;
            int min_element = min({a,b,c});
            arr[i] = min_element;

            if(min_element ==a){
                un1++;
            }
            if(min_element ==b){
                un2++;
            }
            if(min_element ==c){
                un3++;
            }

        }
        return arr[n];
        
    }
};