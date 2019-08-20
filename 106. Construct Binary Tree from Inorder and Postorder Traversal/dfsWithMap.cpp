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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return NULL;
        
        map<int, int> inorderIndex;
        for(int i=0; i<inorder.size(); i++){
            inorderIndex.insert(pair<int, int>(inorder[i], i));
        }
        
        TreeNode* root = createTree(0, postorder.size()-1, postorder, 0, inorder.size()-1, inorder, inorderIndex);
        
        return root;
    }
    
    TreeNode* createTree(int postS, int postE, vector<int> &postorder, int inS, int inE, vector<int> &inorder, map<int, int> &inorderIndex){
        if(postS > postE) return NULL;
        if(postS >= postorder.size() || postE >= postorder.size()) return NULL;
        if(inS >= inorder.size()) return NULL;
        
        TreeNode* node = new TreeNode(postorder[postE]);
        
        int leftSubTreeSize = inorderIndex[postorder[postE]] - inS;
        
        node->left = createTree(postS, postS+leftSubTreeSize-1, postorder, inS, inS+leftSubTreeSize-1, inorder, inorderIndex);
        node->right = createTree(postS+leftSubTreeSize, postE-1, postorder, inS+leftSubTreeSize+1, inE, inorder, inorderIndex);
        
        return node;
        
    }
};