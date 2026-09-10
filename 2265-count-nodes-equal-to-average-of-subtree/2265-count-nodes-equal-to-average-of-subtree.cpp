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
    int sums;
    int nodes;
    node(int val){
        sums=val;
        nodes=1;
    }
};
class Solution {
public:
    node* calculate(TreeNode* root,int& total){
        if(!root->left && !root->right){
            node* head =  new node(root->val);
            if(head->sums/head->nodes == root->val){
                total++;
            }
            return head;
        }else if(!root->right){
            node* head = calculate(root->left,total);
            head->sums += root->val;
            head->nodes++;
            if(head->sums/head->nodes == root->val){
                total++;
            }
            return head;
        }else if(!root->left){
            node* head = calculate(root->right,total);
            head->sums += root->val;
            head->nodes++;
            if(head->sums/head->nodes == root->val){
                total++;
            }
            return head;
        }
        else{
            node* left = calculate(root->left,total);
            node* right = calculate(root->right,total);
            node* head = new node(root->val);
            head->sums+=left->sums+right->sums;
            head->nodes += left->nodes+right->nodes;
            if(head->sums/head->nodes == root->val){
                total++;
            }
            return head;
        }
    }
    int averageOfSubtree(TreeNode* root) {
        int node = 0;
        calculate(root,node);
        return node;
    }
};