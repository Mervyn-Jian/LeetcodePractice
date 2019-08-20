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
    int minDepth(TreeNode* root) {
        int minLeafDepth = INT_MAX;
        int maxLeafDepth = INT_MIN;
        int depth = 0;
        
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        else return 0;
        
        while(!que.empty()){
            
            int qSize = que.size();
            depth++;
            
            for(int i=0; i<qSize; i++){
                TreeNode* node = que.front();
                que.pop();
                
                if(node->left == NULL && node->right == NULL){
                    if(depth > maxLeafDepth) maxLeafDepth = depth;
                    if(depth < minLeafDepth) minLeafDepth = depth;
                }
                
                if(node->left != NULL) que.push(node->left);
                if(node->right != NULL) que.push(node->right);
            }
        }
        
        return minLeafDepth;
    }
};