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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        deque<TreeNode*> que;
        bool fromLeft = true;
        
        if(root != NULL) que.push_back(root);
        
        while(!que.empty()){
            int qSize = que.size();
            
            vector<int> level;
            for(int i=0; i<qSize; i++){
                TreeNode* node;
                
                if(fromLeft) node = *(que.begin()+i);
                else node = *(que.begin()+(qSize-i-1));
                
                level.push_back(node->val);
            }
            
            for(int i=0; i<qSize; i++){
                TreeNode* node = que.front();
                que.pop_front();
                
                if(node->left != NULL) que.push_back(node->left);
                if(node->right != NULL) que.push_back(node->right);
            }
            
            fromLeft = !fromLeft;
            result.push_back(level);
        }
        
        return result;
    }
};