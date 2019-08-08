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
        vector<int> travel;
        inorder(root, travel);
        
        return travel;
    }
    
    void inorder(TreeNode *node, vector<int> &travel){
        if(node!=NULL){
            if(node->left!=NULL) inorder(node->left, travel);
            travel.push_back(node->val);
            if(node->right!=NULL) inorder(node->right, travel);
        }
    }
};