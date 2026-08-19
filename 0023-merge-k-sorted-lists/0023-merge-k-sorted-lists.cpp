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
    ListNode* merge(ListNode* one,ListNode* two){
        ListNode dummy(0);
        ListNode* tail= &dummy;
        while(one && two){
            if(one->val>two->val){
                tail->next=two;
                two=two->next;
            }
            else{
                tail->next=one;
                one=one->next;
            }
            tail=tail->next;
        }
        if(one)tail->next=one;

        if(two)tail->next=two;
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.empty())return NULL;
        if(lists.size()==1){
            return lists[0];
        }
        ListNode* newhead = merge(lists[0],lists[1]);
        for(int i=2;i<lists.size();i++){
            newhead = merge(newhead,lists[i]);
        }
        return newhead;
    }
};