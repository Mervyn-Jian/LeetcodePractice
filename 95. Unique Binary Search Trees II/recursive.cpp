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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> bstTrees;
        if(n>0) bstTrees = createBSTs(1, n);
        
        return bstTrees;
    }
    
    vector<TreeNode*> createBSTs(int numStart, int numEnd){
        vector<TreeNode*> trees;
        vector<TreeNode*> leftTrees;
        vector<TreeNode*> rightTrees;
        
        if(numStart == numEnd){
            TreeNode* root = new TreeNode(numStart);
            trees.push_back(root);
            return trees;
        }else if(numStart > numEnd){
            trees.push_back(NULL);
            return trees;
        }
        
        for(int i=numStart; i<=numEnd; i++){
            
            leftTrees = createBSTs(numStart, i-1);
            rightTrees = createBSTs(i+1, numEnd);
            
            for(int j=0; j<leftTrees.size(); j++){
                for(int k=0; k<rightTrees.size(); k++){
                    TreeNode* root = new TreeNode(i);
                    
                    root->left = leftTrees[j];
                    root->right = rightTrees[k];
                    
                    trees.push_back(root);
                }
            }
        }
        
        return trees;
    }
};