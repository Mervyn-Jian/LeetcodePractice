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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = createTree(0, nums.size()-1, nums);
        return root;
    }
    
    TreeNode* createTree(int s, int e, vector<int> &nums){
        if(s>e || s>=nums.size()) return NULL;
        
        TreeNode* node;
        int nodeIdx = s + (e-s) / 2;
        
        node = new TreeNode(nums[nodeIdx]);
        node->left = createTree(s, nodeIdx-1, nums);
        node->right = createTree(nodeIdx+1, e, nums);
        
        return node;
    }
};