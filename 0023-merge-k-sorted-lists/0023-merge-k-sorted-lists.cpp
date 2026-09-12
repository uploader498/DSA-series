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
class compare{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*>temp;
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                temp.push_back(lists[i]);
            }
        }
        if(temp.empty())return NULL;
        priority_queue<ListNode*,vector<ListNode*>,compare>p(temp.begin(),temp.end());
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(!p.empty()){
            ListNode* temp = p.top();
            p.pop();
            tail->next=temp;
            tail=tail->next;
            if(temp->next){
                p.push(temp->next);
            }
        }
        return dummy.next;
    }
};