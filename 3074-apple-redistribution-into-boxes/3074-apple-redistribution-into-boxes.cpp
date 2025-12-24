class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());
        int n = apple.size();
        int m = capacity.size();
        int total=0;
        for(int i:apple) total+=i;
        int count=0;
        for(int i=0;i<m;i++){
            if(total<=0){
                break;
            }
            total-=capacity[i];
            count++;
        }
        return count;

    }
};