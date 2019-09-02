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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* node = head;
        
        while(node != NULL){
            nodes.push_back(node);
            node = node->next;
        }
        
        if(nodes.size() > 2){ 
            ListNode* preNode = NULL;
            for(int i=0; i<(int)nodes.size()/2; i++){
                ListNode* node1 = nodes[i];
                ListNode* node2 = nodes[nodes.size()-1 -i];
                
                if(preNode != NULL) preNode->next = node1;
                node1->next = node2;
                
                preNode = node2;
            }
            
            //odd case
            if((nodes.size() & 1) == 1){
                preNode->next = nodes[nodes.size()/2];
                preNode = preNode->next;
            }
            preNode->next = NULL;
        }
    }
};