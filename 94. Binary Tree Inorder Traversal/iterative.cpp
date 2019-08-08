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
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        vector<TreeNode*> nodeStack;
        
        if(root == NULL) return nodes;
        
        TreeNode* cur = root;
        while(cur!=NULL || !nodeStack.empty()){
            while(cur != NULL){
                nodeStack.push_back(cur);
                cur = cur->left;
            }
            
            cur = nodeStack.back();
            nodeStack.pop_back();
            
            nodes.push_back(cur->val);
            cur = cur->right;
        }
        
        return nodes;
    }
    
    void inorderTraverse(TreeNode* root,vector<int> &nodes){
        if(root != NULL){
            if(root->left != NULL) inorderTraverse(root->left, nodes);
            nodes.push_back(root->val);
            if(root->right != NULL) inorderTraverse(root->right, nodes);
        }
    }
};