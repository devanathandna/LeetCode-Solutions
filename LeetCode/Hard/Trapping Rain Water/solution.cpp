class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0,r=n-1;
        int ans=0;
        int maxl=0,maxr=0;
        while(l<=r){
            if(height[l] <= height[r]){
                if(maxl < height[l]){
                    maxl = height[l];
                }
                else{
                    ans+=(maxl - height[l]);
                }
                l++;
            }
            else{
                if(maxr < height[r]){
                    maxr = height[r];
                }
                else{
                    ans+=(maxr - height[r]);
                }
                r--;
            }
        }
        return ans;
    }
};