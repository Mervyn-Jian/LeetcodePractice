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
        
        preorderTravese(root, preorder);
        
        return preorder;
    }
    
    void preorderTravese(TreeNode* node, vector<int> &preorder){
        if(node == NULL) return;
        preorder.push_back(node->val);
        
        preorderTravese(node->left, preorder);
        preorderTravese(node->right, preorder);
    }
};