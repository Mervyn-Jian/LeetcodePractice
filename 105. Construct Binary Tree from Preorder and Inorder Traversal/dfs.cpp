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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() <= 0 || preorder.size() != inorder.size()) return NULL;
        
        TreeNode* root = createTree(0, preorder.size(), preorder, 0, inorder.size(), inorder);
        
        return root;
    }
    
    TreeNode *createTree(int preS, int preE, vector<int> &preorder, int inS, int inE, vector<int> &inorder){
        if(preS >= preE || preS >= preorder.size()) return NULL;
        if(inS >= inE) return NULL;
        
        TreeNode *node = new TreeNode(preorder[preS]);
        
        int numLeftSubTree;
        for(int i=inS; i<inE; i++){
            if(inorder[i] == node->val){
                numLeftSubTree = i-inS;
                break;
            }
        }
        
        node->left = createTree(preS+1, preE, preorder, inS, inS+numLeftSubTree, inorder);
        node->right = createTree(preS+1+numLeftSubTree, preE, preorder, inS+1+numLeftSubTree, inE, inorder);
        
        return node;
    }
};