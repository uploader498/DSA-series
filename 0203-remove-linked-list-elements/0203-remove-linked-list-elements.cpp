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
    ListNode* removeElements(ListNode* head, int val){
        if(!head)return head;
        while(head && head->val==val){
            ListNode* temp=head;
            head=head->next;
            delete temp;
        }
        if(!head || !head->next)return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr){
            if(curr->val==val){
                prev->next=curr->next;
                delete curr;
            }
            else{
                prev=prev->next;
            }
            curr=prev->next;
        }
        return head;
    }
};