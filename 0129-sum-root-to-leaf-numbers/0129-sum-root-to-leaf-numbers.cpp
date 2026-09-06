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
    void sumleaf(TreeNode* root,int total,vector<int>&sums){
        if(!root)return;
        if(!root->left && !root->right){
            sums.push_back(total*10+root->val);
            return;
        }
        total=total*10+root->val;
        sumleaf(root->left,total,sums);
        sumleaf(root->right,total,sums);
    }
    int sumNumbers(TreeNode* root) {
        int total = 0;
        vector<int>sums;
        sumleaf(root,total,sums);
        int k=0;
        for(int i=0;i<sums.size();i++){
            k += sums[i];
        }
        return k;
    }
};