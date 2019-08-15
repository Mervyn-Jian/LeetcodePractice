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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorder;
        stack<TreeNode*> stack;
        TreeNode* node = root;
        
        while(node != NULL || !stack.empty()){
            TreeNode* inoderNode;
            
            while(node != NULL){
                stack.push(node);
                node = node->left;
            }
            
            node = stack.top();
            stack.pop();
            
            inorder.push_back(node);
            
            node = node->right;
        }
        
        vector<int> vals;
        for(int i=0; i<inorder.size(); i++){
            vals.push_back(inorder[i]->val);
        }
        sort(vals.begin(), vals.end());
        
        for(int i=0; i<inorder.size(); i++){
            if(vals[i] != inorder[i]->val) inorder[i]->val = vals[i];
        }
    }
};