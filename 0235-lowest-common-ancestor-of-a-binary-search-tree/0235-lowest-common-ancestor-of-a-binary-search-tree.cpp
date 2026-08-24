/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lca(TreeNode* root,int l,int up){
        if(root->val>= l && root->val<=up){
            return root;
        }
        else if(root->val>up){
            return lca(root->left,l,up);
        }
        else
        return lca(root->right,l,up);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int lower,upper;
        if(p->val >= q->val){
            lower=q->val;
            upper=p->val;
        }
        else{
            upper=q->val;
            lower=p->val;
        }
        return lca(root,lower,upper);
    }
};