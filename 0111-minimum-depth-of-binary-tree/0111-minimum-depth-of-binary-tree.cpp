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
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        if(!root->left & !root->right)return 1;
        queue<TreeNode*>q;
        q.push(root);
        int level =0;
        int ans =INT_MAX;
        while(!q.empty()){
            int levelsize = q.size();
            TreeNode* temp;
            for(int i=0;i<levelsize;i++){
                temp=q.front();
                q.pop();
                if(!temp->left && !temp->right){
                    ans=min(level,ans);
                }

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            level++;
        }
        return ans+1;
    }
};