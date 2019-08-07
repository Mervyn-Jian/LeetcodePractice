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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
              
        ListNode* pre = dummy;
        ListNode* first = dummy->next;
        ListNode* second;
        if(first!=NULL) second = first->next;
        else{
            ListNode* result = dummy->next;
            delete dummy;
            return result;
        }
        
        while(first!=NULL){
            
            ListNode* tmp;
            if(second!=NULL) tmp = second->next;
            else break;
            
            first->next = tmp;
            second->next = first;
            pre->next = second;
            
            pre = first;
            first = tmp;
            if(first!=NULL) second = first->next;
            else break;
        }   
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};