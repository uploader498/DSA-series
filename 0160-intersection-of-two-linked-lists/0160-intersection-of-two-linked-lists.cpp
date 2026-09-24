/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* one = headA;
        ListNode* two = headB;

        unordered_map<ListNode*,int>map;
        while(one){
            map[one]++;
            one=one->next;
        }
        while(two){
            if(map[two]>0)
            return two;

            two=two->next;
        }
        
        
        return NULL;
    }
};