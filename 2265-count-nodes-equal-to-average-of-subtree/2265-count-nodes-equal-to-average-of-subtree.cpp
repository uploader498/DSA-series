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
    void calculate(TreeNode* root,int& sums,int& nodes){
        if(!root)return;
        calculate(root->left,sums,nodes);
        calculate(root->right,sums,nodes);
        nodes++;
        sums+=root->val;
    }
    void checknodes(TreeNode* root,int& node){
        if(!root)return;
        int sums=0,nodes=0;
        calculate(root,sums,nodes);
        if(sums/nodes == root->val){
            node++;
        }
        checknodes(root->left,node);
        checknodes(root->right,node);
    }
    int averageOfSubtree(TreeNode* root) {
        int node = 0;
        checknodes(root,node);
        return node;
    }
};