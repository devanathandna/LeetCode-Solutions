class Solution {
public:
    vector<string>ans;
    void func(int i,int n,bool a,bool b,bool c,string res){
        if(i==n){
            ans.push_back(res);
            return;
        }
        if(!a){
            func(i+1,n,true,false,false,res+'a');
        }
        if(!b){
            func(i+1,n,false,true,false,res+'b');
        }
        if(!c){
            func(i+1,n,false,false,true,res+'c');
        }
    }
    string getHappyString(int n, int k) {
        func(0,n,false,false,false,"");
        sort(ans.begin(),ans.end());
        if(k-1 >= ans.size()) return "";
        return ans[k-1];
    }
};