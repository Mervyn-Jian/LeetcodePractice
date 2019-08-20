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
    bool isBalanced(TreeNode* root) {
    	// compare depths between left sub tree and right sub tree.

        if(root == NULL) return true;
        
        //caculate new depth starting from current node
        int depthFromLeftSub = depthFromNode(root->left, 1);
        int depthFromRightSub = depthFromNode(root->right, 1);
        
        if(abs(depthFromLeftSub - depthFromRightSub) > 1) return false;
        else{
            return isBalanced(root->right) && isBalanced(root->left);
        }
        
    }
    
    int depthFromNode(TreeNode *node, int depth){
        if(node == NULL) return depth - 1;
        
        int depthFromLeftSub;
        int depthFromRightSub;
        
        depthFromLeftSub = depthFromNode(node->left , depth + 1);
        depthFromRightSub = depthFromNode(node->right , depth + 1);
        
        return max(depthFromLeftSub, depthFromRightSub);
    }
};