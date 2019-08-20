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
    void flatten(TreeNode* root) {
        // preoder travesal in=place -> morris travesal
        TreeNode* flatten = NULL;
        TreeNode* node = root;
        
        while(node != NULL){
            TreeNode* rightNode = node->right;
            TreeNode* leftSubNode;
            
            if(node->left == NULL){
                if(flatten != NULL){
                    flatten->left = NULL;
                    flatten->right = node;
                }
                flatten = node;
                node = rightNode;
            }else{
                leftSubNode = node->left;
                
                while(leftSubNode->right != NULL && leftSubNode->right != rightNode){
                    leftSubNode = leftSubNode->right;
                }
                
                if(leftSubNode->right == NULL){  //create traversal link
                    
                    if(flatten != NULL){
                        flatten->left = NULL;
                        flatten->right = node;
                    }
                    flatten = node;
                    
                    leftSubNode->right = rightNode;
                    node = node->left;
                    
                }else if(leftSubNode->right == rightNode){  // retain tree structure
                    
                    leftSubNode->right = NULL;
                    node = rightNode;
                }
            }
        }
    }
};