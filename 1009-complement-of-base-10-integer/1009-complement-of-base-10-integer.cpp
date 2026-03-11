class Solution {
public:
    int bitwiseComplement(int n) {
        string res="";
        if(n==0) return 1;
        while(n>0){
            int x = n%2;
            if(x==0){
                res+='1';
            }
            else{
                res+='0';
            }
            n/=2;
        }
        cout << res << endl;
        int a = 0;
        for(int i=res.size()-1;i>=0;i--){
            int x = res[i]-'0';
            a = a*2+x;
        }
        return a;
    }
};