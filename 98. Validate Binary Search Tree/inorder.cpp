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
    bool isValidBST(TreeNode* root) {
        //inorder traversal of binary search tree is a sorted array
        
        vector<int> travel;
        inorder(root, travel);
        
        if(travel.size()<=1) return true;
        for(int i=1; i<travel.size(); i++){
            if(travel[i]<=travel[i-1]) return false;
        }
        return true;
    }
    
    void inorder(TreeNode *node, vector<int> &travel){
        if(node!=NULL){
            if(node->left!=NULL) inorder(node->left, travel);
            travel.push_back(node->val);
            if(node->right!=NULL) inorder(node->right, travel);
        }
    }
};