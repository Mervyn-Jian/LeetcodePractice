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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(k<=1) return head;
        
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode *pre = dummy; 
        ListNode *cur = head;
        
        while(cur!=NULL){
            int kcount = k;
            ListNode* nextStart = cur;
            while(kcount>0 && nextStart!=NULL){
                nextStart = nextStart->next;
                kcount--;
            }
            if(kcount!=0) break;
            else{
                reverseList(&pre, &cur, &nextStart);
            }
        }
        
        ListNode* re = dummy->next;
        delete dummy;
        return  re;
    }
    
    void reverseList(ListNode** pre, ListNode** cur, ListNode** nextStart){
        ListNode* a = *cur;
        ListNode* b = (*cur)->next;
        a->next = *nextStart;
        while(b!=(*nextStart)){
            ListNode* tmp = b->next;
            b->next = a;
            a = b;
            b = tmp;
        }
        (*pre)->next = a;
        *pre = *cur;
        *cur = *nextStart;
    }
};