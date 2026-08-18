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
    ListNode* sumer(ListNode* l1,ListNode* l2,int carry){
        if(!l1 && !l2){
            if(carry!=0){
                ListNode* temp = new ListNode(carry);
                return temp;
            }
            return NULL;
        }
        
        ListNode* temp = new ListNode;
        int sum=0;
        ListNode* first;
        ListNode* second;
        if(!l1){
            sum=l2->val;
            second = l2->next;
            first=NULL;
        }
        else if(!l2){
            sum=l1->val;
            second = NULL;
            first=l1->next;
        }
        else{
            sum = l1->val+l2->val;
            first=l1->next;
            second=l2->next;
        }
        sum = sum+carry;
        if(sum>9){
            sum=sum%10;
            carry = 1;
            temp->val=sum;
        }
        else{
            temp->val=sum;
            carry=0;
        }
        temp->next=sumer(first,second,carry);
        return temp;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        return sumer(l1,l2,0);
    }
};