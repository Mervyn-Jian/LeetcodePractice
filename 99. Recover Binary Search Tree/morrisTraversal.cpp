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
    void recoverTree(TreeNode* root) {
        //find two nodes that are in descending order.
        //swap them to matain inorder array is a sorted arry.
        
        TreeNode* node = root;
        
        TreeNode* preNode = NULL;
        TreeNode* wrong1 = NULL;
        TreeNode* wrong2 = NULL;
        
        //morris traversal, link end of left subtree to node in order to traverse node back.
        while(node != NULL){
            if(node->left == NULL){
                if(wrong1 == NULL &&preNode != NULL && preNode->val > node->val){
                    wrong1 = preNode;
                }
                if(wrong1 != NULL &&preNode != NULL && preNode->val > node->val){
                    wrong2 = node;
                }
                
                preNode = node;
                node = node->right;
            }else{
                TreeNode* subTreeNode = node->left;
                while(subTreeNode->right != node && subTreeNode->right != NULL){
                    subTreeNode = subTreeNode->right;
                }
                
                if(subTreeNode->right == NULL){    //link node, and start traversing
                    subTreeNode->right = node;
                    node = node->left;
                }else if(subTreeNode->right == node){    //break link, and come node back.
                    
                    subTreeNode->right = NULL;
                    
                    if(wrong1 == NULL &&preNode != NULL && preNode->val > node->val){
                        wrong1 = preNode;
                    }
                    if(wrong1 != NULL &&preNode != NULL && preNode->val > node->val){
                        wrong2 = node;
                    }

                    preNode = node;
                    node = node->right;
                }
            }
        }
        
        //swap wrong node values
        if(wrong1 != NULL && wrong2 != NULL) swap(wrong1->val, wrong2->val);

    }
};