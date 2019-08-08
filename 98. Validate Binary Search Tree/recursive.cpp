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
    bool isValidBST(TreeNode* root) {
        return nodeValid(root, NULL, NULL);
    }
    
    bool nodeValid(TreeNode* node, TreeNode* low, TreeNode* high){
        if(node==NULL) return true;
        if(low!=NULL && node->val <= low->val) return false;
        if(high!=NULL && node->val >= high->val) return false;
        
        bool result;
        result = nodeValid(node->left, low, node) && nodeValid(node->right, node, high);
        
        return result;
    }
};