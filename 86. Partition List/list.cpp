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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = NULL;
        ListNode* greaterEqual = NULL;
        
        ListNode* node = head;
        
        ListNode* newHead = NULL;
        ListNode* greaterEqualHead = NULL;
        
        while(node != NULL){
            if(node->val < x){
                if(less == NULL){
                    less = node;
                    newHead = node;
                }else{
                    less->next = node;
                    less = less->next;
                }
            }else{
                if(greaterEqual == NULL){
                    greaterEqual = node;
                    greaterEqualHead = node;
                }else{
                    greaterEqual->next = node;
                    greaterEqual = greaterEqual->next;
                }
            }
            
            node = node->next;
        }
       
        if(less != NULL) less->next = greaterEqualHead;
        else newHead = greaterEqualHead;
        
        if(greaterEqual != NULL) greaterEqual->next = NULL;
        
        return newHead;
    }
};