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
    ListNode* mergeklist(vector<ListNode*>lists,int start,int end){
        if(start==end){
            return lists[start];
        }
        if(start+1==end){
            return merge(lists[start],lists[end]);
        }
        int mid = (start+end)/2;
        ListNode* left = mergeklist(lists,start,mid);
        ListNode* right = mergeklist(lists,mid+1,end);
        return merge(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.empty())return NULL;
        if(lists.size()==1){
            return lists[0];
        }
        return mergeklist(lists,0,lists.size()-1);
        }
};