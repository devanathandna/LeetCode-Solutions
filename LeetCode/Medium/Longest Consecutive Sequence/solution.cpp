class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        for(int i:nums){
            pq.push(i);
        }
        int maxi = 0;
        int start = pq.top();
        pq.pop();
        int count=1;
        while(!pq.empty()){
            int next = pq.top();
            
            if(next == start+1){
                start = next;
                count++;
            }
            else if(next==start){
            }
            else{
                count=1;
                start = next;
            }
            maxi = max(maxi,count);
            pq.pop();
        }
        return maxi;
    }
};