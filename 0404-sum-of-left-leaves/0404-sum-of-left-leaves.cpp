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
    void sm(TreeNode* root,int& s){
        if(!root)return;

        if(root->left && !root->left->left && !root->left->right){
            s+=root->left->val;
        }
        sm(root->left,s);
        sm(root->right,s);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)return 0;

        int s=0;
        sm(root,s);
        return s;
    }
};