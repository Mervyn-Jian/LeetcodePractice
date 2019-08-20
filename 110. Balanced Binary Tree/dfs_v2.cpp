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
        if(root == NULL) return true;
        
        //caculate new depth starting from current node
        int height = depthFromNode(root, 1);
        
        return (height != -1);
    }
    
    int depthFromNode(TreeNode *node, int depth){
        if(node == NULL) return depth - 1;
        
        int depthFromLeftSub;
        int depthFromRightSub;
        
        depthFromLeftSub = depthFromNode(node->left , depth + 1);
        depthFromRightSub = depthFromNode(node->right , depth + 1);
        
        if(depthFromLeftSub == -1 || depthFromRightSub == -1) return -1;
        if(abs(depthFromLeftSub - depthFromRightSub) > 1) return -1;
        
        return max(depthFromLeftSub, depthFromRightSub);
    }
};