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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
          
        preorder(root, 0, result);
        return result;
    }
    
    void preorder(TreeNode* node, int level, vector<vector<int>>& result){
        if(node==NULL) return;
        
        if(result.size()<level+1){
            result.push_back(vector<int>());
        }
        
        result[level].push_back(node->val);
        
        preorder(node->left, level+1, result);
        preorder(node->right, level+1, result);
    }
};