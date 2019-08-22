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
    int sumNumbers(TreeNode* root) {
        int sumNum = 0;
        
        if(root != NULL) sumNum = getPahtNum(root, 0);
        
        return sumNum;
    }
    
    int getPahtNum(TreeNode* node, int curNum){
        
        int num = curNum*10 + node->val;
        int leftNum = 0;
        int rightNum = 0;
        if(node->left == NULL && node->right == NULL){
            return num;
        }
        
        if(node->left != NULL) leftNum = getPahtNum(node->left, num);
        if(node->right != NULL) rightNum = getPahtNum(node->right, num);
        
        return rightNum + leftNum;
    }
};