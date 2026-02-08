class DSU {
public:
    vector<int>parent,sz;
    DSU(int n){
        sz.resize(n+1,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool Union(int x,int y){
        int ulp_x = find(x);
        int ulp_y = find(y);
        if(ulp_x == ulp_y) return false;
        if(sz[ulp_x] > sz[ulp_y]){
            parent[ulp_y] = parent[ulp_x];
            sz[ulp_x]+=sz[ulp_y];
        }
        else{
            parent[ulp_x] = parent[ulp_y];
            sz[ulp_y] +=sz[ulp_x];
        }
        return true;
    }


};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int ans =1;
        int maxi = 0;
        for(int i:nums){
            maxi  = max(maxi,i);
        }

        DSU ds(maxi+1);
        unordered_map<int,int>mpp;
        for(int i:nums){
            for(int f=2;f<=sqrt(i);f++){
                if(i%f==0){
                    ds.Union(i,f);
                    ds.Union(i,i/f);
                }
            }
        }

        for(int i=0;i<n;i++){
            ans = max(ans, ++mpp[ds.find(nums[i])]);
        }

        return ans;
    }
};