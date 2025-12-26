class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int nn=0,y=0;
        int total=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                total++;
                y++;
            }
            else{
                total--;
                nn++;
            }
        }
        if(y==0) return 0;
        if(total<0){
            total= total*-1;
        }
        return total;
    }
};