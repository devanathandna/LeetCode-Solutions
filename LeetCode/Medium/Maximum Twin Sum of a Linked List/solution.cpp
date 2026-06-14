/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode*temp = head;
        int n =0;
        while(temp){
            temp=temp->next;
            n++;
        }
        int sizee = n/2;
        vector<int>arr(sizee);
        temp = head;
        int maxi = INT_MIN;
        int i=0;
        while(temp){
            if(i<sizee){
                arr[i] = temp->val;
                temp=temp->next;
                i++;
            }
            else{
                arr[sizee-1]+=temp->val;
                maxi = max(maxi,arr[sizee-1]);
                temp=temp->next;
                sizee--;
            }
        }

return maxi;
    }
};