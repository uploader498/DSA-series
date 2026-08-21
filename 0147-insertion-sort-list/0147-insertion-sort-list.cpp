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
    ListNode* insertionSortList(ListNode* head){
        if(!head || !head->next)return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr){
            if(curr->val<prev->val){
                ListNode* reset =head;
                while(reset->next->val<curr->val && reset->val<curr->val){
                    reset=reset->next;
                }
                if(reset->val>curr->val){
                    prev->next=curr->next;
                    curr->next=reset;
                    head=curr;
                }
                else{
                    prev->next=curr->next;
                    curr->next=reset->next;
                    reset->next=curr;
                }
                curr=prev->next;
            }
            else{
                prev=prev->next;
                curr=curr->next;
            }
        }
        return head;
    }
};