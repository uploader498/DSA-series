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
    bool isSymmetric(TreeNode* root){
        if(!root->left && !root->right){
            return true;
        }
        if(!root->left || !root->right){
            return false;
        }
        stack<TreeNode*>left;
        stack<TreeNode*>right;
        left.push(root->left);
        right.push(root->right);
        while(!left.empty() && !right.empty()){
            if(left.top()->val != right.top()->val){
                return false;
            }
            TreeNode* lefter = left.top();
            left.pop();
            TreeNode* righter = right.top();
            right.pop();
            if(lefter->left && !righter->right || !lefter->right && righter->left){
                return false;
            }
            if(!lefter->left && righter->right || lefter->right && !righter->left){
                return false;
            }

            if(lefter->left && righter->right){
            left.push(lefter->left);
            right.push(righter->right);
            }
            if(lefter->right && righter->left){
            left.push(lefter->right);
            right.push(righter->left);
            }
        }
        if(!left.empty() || !right.empty()){
            return false;
        }
        return true;
    }
};