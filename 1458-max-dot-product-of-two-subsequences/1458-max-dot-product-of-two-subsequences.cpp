class Solution {
public:
    int n,m;
    int ans = INT_MIN;
    int func(int i,int j,bool taken,vector<int>& nums1, vector<int>& nums2,vector<vector<vector<int>>>&dp){
        if(i==n || j==m){
            return taken ? 0 : INT_MIN;
        }

        if(dp[i][j][taken]!=INT_MIN) return dp[i][j][taken];

        int prod = nums1[i]*nums2[j];

        int next = func(i+1,j+1,true,nums1,nums2,dp);

        int take;
        if(next!=INT_MIN){
            take = max(prod,prod+next);
        }
            

        
        int nottake = max(func(i+1,j,taken,nums1,nums2,dp),func(i,j+1,taken,nums1,nums2,dp));
        ans = max(ans,max(take,nottake));
        return dp[i][j][taken] = max(take,nottake);

    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(2,INT_MIN)));
        int c = func(0,0,false,nums1,nums2,dp);
        cout << ans << endl;
        return c;
    }
};