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
    TreeNode* formtree(vector<int>& preorder,int lower,int upper,int& index){
        if(index>=preorder.size())return NULL;
        if(preorder[index]>upper || preorder[index]<lower){
            return NULL;
        }
        TreeNode* temp = new TreeNode(preorder[index++]);
        temp->left=formtree(preorder,lower,temp->val,index);
        temp->right=formtree(preorder,temp->val,upper,index);
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return formtree(preorder,INT_MIN,INT_MAX,index);
    }
};