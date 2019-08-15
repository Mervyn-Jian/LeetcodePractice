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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return equalflipTree(root1, root2);
    }
    
    bool equalflipTree(TreeNode* root1, TreeNode* root2){
        if(root1==NULL && root2==NULL) return true;
        else if(root1==NULL || root2==NULL) return false;
        else{
            if(root1->val == root2->val){
                bool case1 = equalflipTree(root1->left, root2->right) && equalflipTree(root1->right, root2->left);
                bool case2 = equalflipTree(root1->left, root2->left) && equalflipTree(root1->right, root2->right);
                
                return (case1 || case2);
            }else{
                return false;
            }
        }
    }
};