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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* formtree(vector<int>tree,int start,int end){
        if(start>end){
            return NULL;
        }
        int mid = (start+end)/2;
        TreeNode* temp = new TreeNode(tree[mid]);
        temp->left = formtree(tree,start,mid-1);
        temp->right = formtree(tree,mid+1,end);
        return temp;
    }
    TreeNode* sortedListToBST(ListNode* head){
        if(!head)return NULL;

        vector<int>tree;
        while(head){
            tree.push_back(head->val);
            head=head->next;
        }
        return formtree(tree,0,tree.size()-1);
    }
};