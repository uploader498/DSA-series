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
    ListNode* reverse(ListNode* start){
        ListNode* prev = NULL;
        ListNode* curr = start;
        ListNode* ahead = start;
        while(curr){
            ahead=ahead->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k){
        if(!head || !head->next)return head;
        ListNode* pointer = head;
        for(int i=1;i<k;i++){
            if(!pointer){
                return head;
            }   
            pointer=pointer->next;
        } 
        if(!pointer){
            return head;
        }   
        ListNode* hold = pointer->next;
        ListNode* oldhead = head;
        pointer->next=NULL;
        head = reverse(head);
        oldhead->next=reverseKGroup(hold,k);
        return head;
    }
};