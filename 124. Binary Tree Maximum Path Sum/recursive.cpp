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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        if(root == NULL) return maxSum;
        
        maxPathSumStartFromNode(root, maxSum);
        return maxSum;
    }
    
    int maxPathSumStartFromNode(TreeNode* node, int &maxSum){
        if(node == NULL) return 0;
        
        // get non negative value is to preserve the property that 
        // the path must contain at least one node.
        int leftSum = max(0, maxPathSumStartFromNode(node->left, maxSum));
        int rightSum = max(0, maxPathSumStartFromNode(node->right, maxSum));
        
        maxSum = max(maxSum, leftSum + rightSum + node->val);
        
        return node->val + max(leftSum, rightSum);
    }
};