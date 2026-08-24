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
    TreeNode* create(vector<int>&arr,int index){
        if(index>=arr.size())return NULL;
        TreeNode* temp = new TreeNode(arr[index++]);
        temp->right=create(arr,index);
        return temp;
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>ans;
        while(root){
            if(!root->left){
                ans.push_back(root->val);
                root=root->right;
            }
            else{
                TreeNode* runner = root->left;
                while(runner->right && runner->right!=root){
                    runner=runner->right;
                }
                if(runner->right){
                    runner->right=NULL;
                    ans.push_back(root->val);
                    root=root->right;
                }
                else{
                    runner->right=root;
                    root=root->left;
                }
            }
        }
        return create(ans,0);
    }
};