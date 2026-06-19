class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        vector<int>suf(n);
        vector<int>pre(n);
        suf[0] = nums[0];
        pre[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            suf[i] = suf[i-1]*nums[i];
        }
        for(int i=n-2;i>=0;i--){
            pre[i] = pre[i+1]*nums[i];
        }
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            int left = (i==0) ? 1 : suf[i-1];
            int right = (i==n-1) ? 1 : pre[i+1];
            ans[i] = left * right;
        }

        for(int i:suf) cout << i << " ";
        cout << endl;
        for(int i:pre) cout << i << " ";
        return ans;
    }
};