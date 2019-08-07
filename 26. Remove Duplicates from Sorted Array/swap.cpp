class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=0) return 0;
        if(nums.size()==1) return 1;
        
        int swapStart = 1;
        int cur = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>cur){
                cur = nums[i];
                swap(&nums[swapStart], &nums[i]);
                swapStart++;
            } 
        }
        
        return swapStart;
    }
    
    void swap(int *a, int *b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
};