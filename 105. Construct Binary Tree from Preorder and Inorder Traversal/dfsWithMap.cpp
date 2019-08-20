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
        
        map<int, int> inorderIndex;
        for(int i=0; i<inorder.size(); i++){
            inorderIndex.insert(pair<int,int>(inorder[i], i));
        }
        
        TreeNode* root = createTree(0, preorder.size(), preorder, 0, inorder.size(), inorder, inorderIndex);
        
        return root;
    }
    
    TreeNode *createTree(int preS, int preE, vector<int> &preorder, int inS, int inE, vector<int> &inorder, map<int, int> &inorderIndex){
        if(preS >= preE || preS >= preorder.size()) return NULL;
        if(inS >= inE) return NULL;
        
        TreeNode *node = new TreeNode(preorder[preS]);
        
        int numLeftSubTree;
        numLeftSubTree = inorderIndex[preorder[preS]] - inS;
        
        node->left = createTree(preS+1, preE, preorder, inS, inS+numLeftSubTree, inorder, inorderIndex);
        node->right = createTree(preS+1+numLeftSubTree, preE, preorder, inS+1+numLeftSubTree, inE, inorder, inorderIndex);
        
        return node;
    }
};