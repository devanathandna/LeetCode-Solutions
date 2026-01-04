class Solution {
public:
    int func(int val){
        int c=0;
        int sum=0;
        for(int i=1;i*i<=val;i++){
            if(val%i==0){
                if(i!= val/i){
                    c+=2;
                    sum+=i;
                    sum+=(val/i);
                }
                else{
                    c+=1;
                    sum+=i;
                }
            }
        }

        return c==4 ? sum : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            count+=func(nums[i]);
        }
        return count;
    }
};