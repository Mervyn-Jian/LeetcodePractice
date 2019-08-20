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
    bool hasPathSum(TreeNode* root, int sum) {
        set<int> pathSum;
        
        allPathSum(root, 0, pathSum);
        return ( pathSum.find(sum) != pathSum.end() );
    }
    
    void allPathSum(TreeNode* node, int sum, set<int> &pathSum){
        if(node == NULL) return;
        if(node->left == NULL && node->right == NULL){
            pathSum.insert(sum + node->val);
            return;
        }
        
        allPathSum(node->left, sum+node->val, pathSum);
        allPathSum(node->right, sum+node->val, pathSum);
    }
};