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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k<0) return head;
        
        vector<ListNode*> listPts;
        ListNode* node = head;
        while(node!=NULL){
            listPts.push_back(node);
            node = node->next;
        }
        int n = listPts.size();
        int s = 0;
        k %=n;
        for(int i=0; i<k; i++){
            s--;
            if(s<0) s=n-1;
        }
        
        int count=0;
        ListNode* ref = listPts[s]; 
        ListNode* cur =ref;
        count++;
        s = (s+1)%n; 
        while(count<n){
            cur->next = listPts[s];
            cur = cur->next;
            count++;
            s = (s+1)%n;
        }
        cur->next = NULL;
        
        return ref;
    }
};