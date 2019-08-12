/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* node = head;
        dummy ->next = head;
        
        while(node!=NULL){
            ListNode* tmpNode = node;
            while(tmpNode->next!=NULL && tmpNode->next->val == node->val){
                tmpNode = tmpNode->next;
            }
            node->next = tmpNode->next;
            node = node->next;
        }
        
        node = dummy->next;
        delete dummy;
        
        return node;
    }
};