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
    void inorder(TreeNode* root,vector<int>&arr){
        if(!root)return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* creation(vector<int>&arr,int start,int end){
        if(start>end)return NULL;
        int mid = start+(end-start+1)/2;
        TreeNode* temp = new TreeNode(arr[mid]);
        temp->left = creation(arr,start,mid-1);
        temp->right = creation(arr,mid+1,end);
        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        inorder(root,arr);
        return creation(arr,0,arr.size()-1);
    }
};