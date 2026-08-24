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
    TreeNode* creation(TreeNode* root,int& prev){
        if(!root)return NULL;
        creation(root->right,prev);
        root->val+=prev;
        prev=root->val;
        creation(root->left,prev);
        return root;
    }
    TreeNode* convertBST(TreeNode* root) {
        int prev =0;
        return creation(root,prev);
    }
};