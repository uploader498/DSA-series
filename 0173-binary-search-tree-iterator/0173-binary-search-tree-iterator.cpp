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
class BSTIterator {
public:
    stack<TreeNode*>s1;
    BSTIterator(TreeNode* root) {
        while(root){
            s1.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode* root;
        int val = s1.top()->val;
        root = s1.top()->right;
        s1.pop();
        while(root){
            s1.push(root);
            root=root->left;
        }
        return val;
    }
    
    bool hasNext() {
        return !s1.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */