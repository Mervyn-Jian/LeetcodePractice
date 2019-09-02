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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* cycleBegin = head;
        
        //speed of the fast pointer is double as speed of slow pointer
        //when slow pointer encounters fast pointer, there is a cycle.
        //the distance between head and cycle entry is dc,
        //the distance between slow pointer and cycle entry is ds,
        //the distance traversed by fast pointer is df,
        //the length of cycle is lc,
        //the times that traverse the cycle when slow pointer meets fast pointer is n.
        // 2*(dc + ds) = (dc+ds) + n*lc
        // ds + dc = n*lc
        // dc = (n-1)*lc + (n-ds)
        // dc = n - ds
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                while(cycleBegin != slow){
                    slow = slow->next;
                    cycleBegin = cycleBegin->next;
                }
                return cycleBegin;
            }
        }
        
        return NULL;
    }
};