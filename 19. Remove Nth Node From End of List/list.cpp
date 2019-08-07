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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode *first = dummy;
        ListNode *second = dummy;
        
        if(head==NULL) return head;
        
        for(int i=0; i<=n; i++){
            first= first->next;
        }
        
        while(first!=NULL){
            first= first->next;
            second = second->next;
        }
        if(second->next!=NULL)  second->next = second->next->next;
        
        return dummy->next;
    }
};