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
    ListNode* oddEvenList(ListNode* head){
        if(!head || !head->next)return head;

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* connector = head->next;
        ListNode* ahead;
        while(curr){
            ahead=curr->next;
            prev->next=ahead;
            prev=curr;
            curr=ahead;
        }
        ListNode* run=head;
        while(run->next){
            run=run->next;
        }
        run->next=connector;
        return head;
    }
};