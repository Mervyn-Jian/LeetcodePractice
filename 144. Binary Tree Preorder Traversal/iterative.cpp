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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        stack<TreeNode*> stack;
        
        if(root != NULL) stack.push(root);
        
        while(!stack.empty()){
            TreeNode* node = stack.top();
            stack.pop();
            
            preorder.push_back(node->val);
            
            if(node->right != NULL) stack.push(node->right);
            if(node->left != NULL) stack.push(node->left);
            
        }
        
        return preorder;
    }
    
};