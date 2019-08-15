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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;
        
        ListNode* dummy = new ListNode(INT_MIN);
        int count = 1;
        ListNode* slow;
        ListNode* fast;
        ListNode* preReverse = NULL;
        ListNode* endReverse = NULL;
        
        dummy->next = head;
        slow = dummy;
        fast = head;
        
        while(fast != NULL){
            if(count <= m){
                if(count == m){
                    preReverse = slow;
                    endReverse = fast;
                }
            
                slow = fast;
                fast = fast->next;
                count++;
            }else if(count > m && count <= n){
                ListNode* next = fast->next;
                fast->next = slow;
                
                slow = fast;
                fast = next;
                count++;
            }else if(count > n){
                break;
            }
        }
        
        if(preReverse != NULL){
            preReverse->next = slow;
            endReverse->next = fast;
        }
        
        fast = dummy->next;
        delete dummy;
        
        return fast;
    }
};