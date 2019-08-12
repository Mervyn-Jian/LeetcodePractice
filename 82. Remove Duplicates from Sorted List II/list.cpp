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
        ListNode* preNode = dummy;
        dummy ->next = head;
              
        while(node!=NULL){
            ListNode* tmpNode = node;
            int count = 1;
            
            while(tmpNode->next!=NULL && tmpNode->next->val == node->val){
                tmpNode = tmpNode->next;
                count++;
            }
            
            if(count>1){
                preNode->next = tmpNode->next;
                node = preNode->next;
            }else{
                preNode = node;
                node = node->next;
            }
        }
        
        node = dummy->next;
        delete dummy;
        
        return node;
    }
};