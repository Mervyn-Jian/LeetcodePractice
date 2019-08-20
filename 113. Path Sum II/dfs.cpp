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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> pathes;
        
        allPathSum(root, 0, sum, path, pathes);
        return pathes;
    }
    
    void allPathSum(TreeNode* node, int curSum, int sum, vector<int> &path, vector<vector<int>> &pathes){
        if(node == NULL) return;

        path.push_back(node->val);
        
        if(node->left == NULL && node->right == NULL){
            if(sum == curSum + node->val){
                pathes.push_back(path);
            }
            
            path.pop_back();
            return;
        }
        
        allPathSum(node->left, curSum+node->val, sum, path, pathes);
        allPathSum(node->right, curSum+node->val, sum, path, pathes);
        
        path.pop_back();
    }
};