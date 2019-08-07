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
        ListNode* merge;
        if(lists.size()<=0) return NULL;
        if(lists.size()==1) return lists[0];
        
        merge = merge2Lists(lists[0], lists[1]);
        for(int i=2; i<lists.size(); i++){
            merge = merge2Lists(merge, lists[i]);
        }
        
        return merge;
    }
    
    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        if(l1->val<=l2->val){
            l1->next = merge2Lists(l1->next, l2);
            return l1;
        }else{
            l2->next = merge2Lists(l1, l2->next);
            return l2;
        }
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