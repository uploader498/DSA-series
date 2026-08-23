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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        vector<int>ans;
        while(root1){
            s1.push(root1);
            root1=root1->left;
        }
        while(root2){
            s2.push(root2);
            root2=root2->left;
        }
        while(!s1.empty() && !s2.empty()){
            if(s1.top()->val<s2.top()->val){
                root1=s1.top()->right;
                ans.push_back(s1.top()->val);
                s1.pop();
            }
            else{
                root2=s2.top()->right;
                ans.push_back(s2.top()->val);
                s2.pop();
            }
            while(root1){
                s1.push(root1);
                root1=root1->left;
            }
            while(root2){
                s2.push(root2);
                root2=root2->left;
            }
        }
        while(!s1.empty()){
            root1=s1.top()->right;
            ans.push_back(s1.top()->val);
            s1.pop();
            while(root1){
                s1.push(root1);
                root1=root1->left;
            }
        }
        while(!s2.empty()){
            root2=s2.top()->right;
            ans.push_back(s2.top()->val);
            s2.pop();
            while(root2){
                s2.push(root2);
                root2=root2->left;
            }
        }
        return ans;
    }
};