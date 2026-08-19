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
    void recoverTree(TreeNode* root) {
        TreeNode* first=NULL;
        TreeNode* second=NULL;
        TreeNode* prev = NULL;
        TreeNode* curr = NULL;
        while(root){
            if(!root->left){
                prev=curr;
                curr=root;
                if(prev && root->val<prev->val){
                    if(!first){
                    first=prev;
                    }
                    second=curr;
                }
                root=root->right;
            }
            else{
                TreeNode* parent = root->left;
                while(parent->right && parent->right!=root){
                    parent=parent->right;
                }
                if(parent->right==NULL){
                    parent->right=root;
                    root=root->left;
                }
                else{
                    parent->right=NULL;
                    prev=curr;
                    curr=root;
                    if(prev && root->val<prev->val){
                        if(!first){
                            first=prev;
                        }
                        second=curr;
                    }
                    root=root->right;
                }
            }
        }
        int num = first->val;
        first->val=second->val;
        second->val=num;
    }
};