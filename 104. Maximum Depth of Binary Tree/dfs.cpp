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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        
        if(root != NULL) dfs(root, 1, depth);
        
        return depth;
    }
    
    void dfs(TreeNode* node, int level, int &depth){
        if(node != NULL){
            depth = max(depth,level);
            
            if(node->left != NULL) dfs(node->left, level+1, depth);
            if(node->right != NULL) dfs(node->right, level+1, depth);
        }
    }
};