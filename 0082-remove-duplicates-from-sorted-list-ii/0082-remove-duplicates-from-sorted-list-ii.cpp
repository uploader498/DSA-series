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
    ListNode* deleteDuplicates(ListNode* head){
        if(!head)return head;
        if(head->next==NULL)return head;
        ListNode* hod = head;
        ListNode* pod = head->next;
        while(pod->val==hod->val && pod->next){
            pod=pod->next;
        }
        if(pod->next==NULL && hod->val==pod->val){
            return NULL;
        }
        if(hod->next->val==hod->val){
            pod = deleteDuplicates(pod);
            return pod;
        }
        else{
            hod->next = deleteDuplicates(pod);
            return hod;
        }
    }
};