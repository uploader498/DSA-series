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
    int position(vector<int>inorder,int val){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }
    TreeNode* build(vector<int>&preorder,vector<int>inorder,int instart,int inend,int& index){
        if(index>=preorder.size() || instart>instart || inend<instart){
            return NULL;
        }
        int pos = position(inorder,preorder[index]);
        TreeNode* temp = new TreeNode(preorder[index++]);
        temp->left = build(preorder,inorder,instart,pos-1,index);
        temp->right = build(preorder,inorder,pos+1,inend,index);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return build(preorder,inorder,0,inorder.size()-1,index);
    }
};