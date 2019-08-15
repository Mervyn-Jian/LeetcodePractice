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
        //find two nodes that are in descending order.
        //swap them to matain inorder array is a sorted arry.
        
        stack<TreeNode*> stack;
        TreeNode* node = root;
        
        TreeNode* preNode = NULL;
        TreeNode* wrong1 = NULL;
        TreeNode* wrong2 = NULL;
        
        while(node != NULL || !stack.empty()){
            while(node != NULL){
                stack.push(node);
                node = node->left;
            }
            
            node = stack.top();
            stack.pop();
            
            if(wrong1 == NULL && preNode != NULL && preNode->val >= node->val){
                wrong1 = preNode;
            }
            if(wrong1 != NULL && preNode != NULL && preNode->val >= node->val){
                wrong2 = node;
            }
            
            preNode = node;
            node = node->right;
        }
        
        //swap wrong node values
        if(wrong1 != NULL && wrong2 != NULL) swap(wrong1->val, wrong2->val);

    }
};