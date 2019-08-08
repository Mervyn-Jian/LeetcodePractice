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
        
        deque<TreeNode*> treeQue;
        treeQue.push_back(root);
        treeQue.push_back(root);
        
        while(!treeQue.empty()){
            TreeNode* tr1;
            TreeNode* tr2;
            
            tr1 = treeQue.front();
            treeQue.pop_front();
            tr2 = treeQue.front();
            treeQue.pop_front();
            
            if(tr1==NULL && tr2==NULL) continue;
            if(tr1==NULL || tr2==NULL) return false;
            
            if(tr1->val == tr2->val){
                treeQue.push_back(tr1->left);
                treeQue.push_back(tr2->right);
                
                treeQue.push_back(tr2->left);
                treeQue.push_back(tr1->right);
            }else{
                return false;
            }
        }
        
        return true;
        
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