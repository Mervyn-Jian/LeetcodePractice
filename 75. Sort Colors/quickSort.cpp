class Solution {
public:
    void sortColors(vector<int>& nums) {
        qsort(0, nums.size()-1, nums);
    }
    
    void qsort(int s, int e, vector<int> &nums){
        if(s<e){
            int q = partition(s, e, nums);
            qsort(s, q-1, nums);
            qsort(q+1, e, nums);
        }
    }
    
    int partition(int s, int e, vector<int> &nums){
        int j=s-1;
        for(int i=s; i<e; i++){
            if(nums[i]<nums[e]){
                j++;
                swap(nums[i], nums[j]);
            }
        }
        j++;
        swap(nums[j], nums[e]);
        return j;
    }
};