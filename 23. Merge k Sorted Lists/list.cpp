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
        vector<int> arr;
        for(int i=0; i<lists.size(); i++){
            while(lists[i]!=NULL){
                arr.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        
        //sort(arr.begin(), arr.end());
        quickSort(arr, 0, ((int)arr.size())-1);
        
        ListNode* dummy=NULL;
        ListNode* p;
        
        if(arr.size()<=0) return dummy;
        
        dummy = new ListNode(0);
        p = dummy;
        
        for(int i=0; i<arr.size(); i++){
            ListNode* cur = new ListNode(arr[i]);
            p->next = cur;
            p = p->next;
        }
        
        return dummy->next;
        
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