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
        deque<TreeNode*> que;
        vector<vector<int>> result;
          
        if(root!=NULL) que.push_back(root);
        while(!que.empty()){
            int n = que.size();
            vector<int> res;
            for(int i=0; i<n; i++){
                TreeNode* node = que.front();
                que.pop_front();
                res.push_back(node->val);
                
                if(node->left!=NULL) que.push_back(node->left);
                if(node->right!=NULL) que.push_back(node->right);
            }
            result.push_back(res);
        }
        
        return result;
    }
};