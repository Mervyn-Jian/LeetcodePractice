/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int nextDigit = 0;
        ListNode *p1, *p2, *cur;
        ListNode *dummy = new ListNode(0);
        
        p1 = l1;
        p2 = l2;
        cur = dummy;
        
        while(p1 || p2 || nextDigit!=0){
            int sum = (p1? p1->val : 0) + (p2? p2->val : 0) + nextDigit;
            ListNode *p = new ListNode(sum % 10);
            nextDigit = sum / 10;
            
            cur->next = p;
            cur = p;
            
            p1 = (p1? p1->next : p1);
            p2 = (p2? p2->next : p2);
        }
        
        return dummy->next;
    }
};