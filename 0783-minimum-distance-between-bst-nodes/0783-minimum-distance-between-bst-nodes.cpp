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
    
    int minDiffInBST(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* curr = NULL;
        int smallest = INT_MAX;
        while(root){
            if(!root->left){
                prev = curr;
                curr=root;
                if(prev){
                    smallest = min(smallest,curr->val-prev->val);
                }
                root=root->right;
            }
            else{
                TreeNode* runner = root->left;
                while(runner->right && runner->right!=root){
                    runner=runner->right;
                }
                if(!runner->right){
                    runner->right=root;
                    root=root->left;
                }
                else{
                    runner->right=NULL;
                    prev=curr;
                    curr=root;
                    if(prev){
                        smallest=min(smallest,curr->val-prev->val);
                    }
                    root=root->right;
                }
            }
        }
        return smallest;
    }
};