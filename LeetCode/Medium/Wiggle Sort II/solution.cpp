class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int mid = (n+1)/2;
        sort(nums.begin(),nums.end());
        vector<int>first(nums.begin(),nums.begin()+mid);
        vector<int>last(nums.begin()+mid,nums.end());
        reverse(first.begin(),first.end());
        reverse(last.begin(),last.end());
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                nums[i] = first[a];
                a++;
            }
            else{
                nums[i] = last[b];
                b++;
            }
        }
        return;
    }
};