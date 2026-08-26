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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry =0;
        ListNode* tail = new ListNode(0);
        ListNode* tail1 = NULL;
        ListNode* tail2 = NULL;
        ListNode* start1;
        ListNode* start2;
        while(l1!=tail1 || l2!=tail2){
            int sum =0;
            start1=l1;
            start2=l2;
            if(start1!=tail1 && start2!=tail2){
                while(start1->next!=tail1){
                    start1=start1->next;
                }
                while(start2->next!=tail2){
                    start2=start2->next;
                }
                tail1=start1;
                tail2=start2;
                sum = start1->val+start2->val+carry;
                }
                else if(start1==tail1 && start2!=tail2){
                    while(start2->next!=tail2){
                        start2=start2->next;
                    }
                    tail2=start2;
                    sum =start2->val+carry;
                }
                else{
                    while(start1->next!=tail1){
                        start1=start1->next;
                    }
                    tail1=start1;
                    sum =start1->val+carry;
                }
                if(sum>9){
                    sum=sum%10;
                    carry=1;
                }
                else{
                    carry=0;
                }
            ListNode* temp = new ListNode(sum,tail->next);
            tail->next=temp;
        }
        if(carry){
            ListNode* temp = new ListNode(1,tail->next);
            tail->next=temp;
        }
        return tail->next;
    }
};