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
        vector<int> allPathNum;
        
        if(root != NULL) getPahtNums(root, 0, allPathNum);
        
        sumNum = accumulate(allPathNum.begin(), allPathNum.end(), 0);
        return sumNum;
    }
    
    void getPahtNums(TreeNode* node, int curNum, vector<int> &allPathNum){
        
        int num = curNum*10 + node->val;
        
        if(node->left == NULL && node->right == NULL){
            allPathNum.push_back(num);
            return;
        }
        
        if(node->left != NULL) getPahtNums(node->left, num, allPathNum);
        if(node->right != NULL) getPahtNums(node->right, num, allPathNum);
    }
};