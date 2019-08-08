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
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
    
    void invert(TreeNode* node){
        if(node!=NULL){
            if(node->left!=NULL) invert(node->left);
            if(node->right!=NULL) invert(node->right);
        
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
        }
    }
};