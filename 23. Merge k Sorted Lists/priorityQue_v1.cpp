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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode(INT_MIN);
        ListNode *cur = dummy;
        
        class cmp{
            public:
            bool operator()(ListNode* a, ListNode* b){
                return a->val > b->val;
            }
        };
        priority_queue<ListNode*, vector<ListNode*>, cmp> p_que;
        
        for(int i=0; i<lists.size(); i++){
            while(lists[i]!=NULL){
                p_que.push(lists[i]);
                lists[i] = lists[i]->next;
            }
        }
        
        while(!p_que.empty()){
            cur->next = new ListNode(p_que.top()->val);
            p_que.pop();
            cur = cur->next;
        }
        
        ListNode *head=dummy->next;
        delete dummy;
        return head;
    }
    
    void quickSort(vector<int>& list, int start, int end){
        if(start<end){
            int q = partition(list, start, end);
            quickSort(list, start, q-1);
            quickSort(list, q+1, end);
        }
    }
    
    int partition(vector<int>& list, int start, int end){
        int j=start-1;
        for(int i=start; i<end; i++){
            if(list[i] < list[end]){
                j++;
                swap(&list[i], &list[j]);
            }
        }
        swap(&list[j+1], &list[end]);
        return j+1;
    }
    
    void swap(int*a, int*b){
        int temp = *a;
        *a=*b;
        *b = temp;
    }
    
};