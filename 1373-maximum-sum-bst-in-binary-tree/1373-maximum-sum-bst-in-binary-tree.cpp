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
 class node{
    public:
    bool bst;
    int sum;
    int min,max;
    node(int val){
        bst = 1;
        sum = val;
        min =val;
        max=val;
    }
 };

class Solution {
public:
    node* maxsumbst(TreeNode* root,int& sum){
        if(!root->left && !root->right){
            node* head = new node(root->val);
            sum = max(sum,head->sum);
            return head;
        }
        else if(!root->right){
            node* head = maxsumbst(root->left,sum);
            if(head->bst && head->max<root->val){
                head->sum+=root->val;
                head->max=root->val;
                sum = max(sum,head->sum);
                return head;
            }
            else{
                head->bst=0;
                return head;
            }
        }
        else if(!root->left){
            node* head = maxsumbst(root->right,sum);
            if(head->bst && head->min>root->val){
            head->sum+=root->val;
            head->min=root->val;
            sum = max(sum,head->sum);
            return head;
            }
            else{
                head->bst=0;
                return head;
            }
        }
        else{
            node* lefthead= maxsumbst(root->left,sum);
            node* righthead = maxsumbst(root->right,sum);
            if(lefthead->bst && righthead->bst && lefthead->max<root->val && righthead->min>root->val){
                node* head = new node(root->val);
                head->sum+=lefthead->sum+righthead->sum;
                head->max=righthead->max;
                head->min=lefthead->min;
                sum = max(sum,head->sum);
                return head;
            }
            else{
                lefthead->bst=0;
                return lefthead;
            }
        }
    }
    int maxSumBST(TreeNode* root) {
       int sum = 0;
       maxsumbst(root,sum);
       return sum; 
    }
};