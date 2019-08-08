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
    bool isSymmetric(TreeNode* root) {
        // inorder is sysmetric
        if(root == NULL) return true;
        
        return compareSymmetricTree(root, root);
        
    }
    
    bool compareSymmetricTree(TreeNode* tr1, TreeNode* tr2){
        if(tr1==NULL && tr2==NULL) return true;
        if(tr1==NULL || tr2==NULL) return false;
        
        if(tr1->val == tr2->val){
            return compareSymmetricTree(tr1->left, tr2->right) &&
                   compareSymmetricTree(tr2->left, tr1->right);
        }
        
        return false;
    }
};