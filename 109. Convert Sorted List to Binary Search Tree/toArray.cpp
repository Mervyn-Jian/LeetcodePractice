/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        TreeNode* root;
        
        while(head != NULL){
            nums.push_back(head->val);
            head = head->next;
        }
        
        root = createTree(0, nums.size()-1, nums);
        return root;
    }
    
    TreeNode* createTree(int s, int e, vector<int> nums){
        if(s>e) return NULL;
        
        TreeNode* node;
        int nodeIndex = s + (e-s)/2;
        
        node = new TreeNode(nums[nodeIndex]);
        
        node->left = createTree(s, nodeIndex-1, nums);
        node->right = createTree(nodeIndex+1, e, nums);
        
        return node;
    }
};