class Solution {
  public:
    int merge(vector<int>&arr,int l,int mid,int r){
        vector<int>ans;
        int i=l;
        int j=mid+1;
        int cnt=0;
        while(i<=mid && j<=r){
            if(arr[i] <= arr[j]){
                ans.push_back(arr[i]);
                i++;
            }
            else{
                cnt += (mid - i + 1);
                ans.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){
            ans.push_back(arr[i]);
            i++;
        }
        while(j<=r){
            ans.push_back(arr[j]);
            j++;
        }
        for(int k=0;k<ans.size();k++){
            arr[l+k] = ans[k];
        }
        return cnt;
    }
    
    int mergesort(vector<int>& arr, int l, int r){
        if(l>=r) return 0;
        int mid = l + (r-l)/2;
        int cnt=0;
        cnt+=mergesort(arr,l,mid);
        cnt+=mergesort(arr,mid+1,r);
        cnt+=merge(arr,l,mid,r);
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
        return mergesort(arr,0,arr.size()-1);
        
    }
};