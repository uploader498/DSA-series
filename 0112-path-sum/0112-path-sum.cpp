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
    void pathsum(TreeNode* root,int target,int total,bool& v){
        if(!root)return;
        if(!root->left && !root->right){
            if(root->val+total == target){
            v = 1;
            }
            else{
                return;
            }
        }
        
        pathsum(root->left,target,total+root->val,v);
        pathsum(root->right,target,total+root->val,v);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool v =0;
        pathsum(root,targetSum,0,v);
        return v;
    }
};