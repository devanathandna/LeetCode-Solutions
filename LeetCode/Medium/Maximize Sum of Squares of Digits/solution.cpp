class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9LL *num) return "";
        if(sum==0){
            if(num==0) return "0";
            return "";
        }
        int ful = sum/9;
        int rem = sum % 9;

        if(ful > num) return "";
        string ans;

        int use = min(ful,num);
        ans.append(use,'9');

        int used = use;
        if(rem > 0){
            if(used < num){
                ans.push_back(char('0'+rem));
                used++;
            }
            else{
                return "";
            }
        }

        if(used < num) ans.append(num - used,'0');
        return ans;

    }
};