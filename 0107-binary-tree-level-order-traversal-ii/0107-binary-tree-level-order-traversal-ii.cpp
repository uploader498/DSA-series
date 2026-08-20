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
    int height(TreeNode* root){
        if(!root)return 0;

        return 1+max(height(root->left),height(root->right));
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root){
        int sizer = height(root);
        vector<vector<int>>ans(sizer);
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        sizer--;
        while(!q.empty()){
            int levelsize = q.size();
            for(int i=0;i<levelsize;i++){
            TreeNode* temp = q.front();
            q.pop();
            ans[sizer].push_back(temp->val);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            }
            sizer--;
        }
        return ans;
    }
};