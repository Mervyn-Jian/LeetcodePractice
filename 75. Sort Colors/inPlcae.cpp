class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        
        for(int i=0; i<=e; i++){
            if(nums[i]==0){
                swap(nums[s], nums[i]);
                s++;
            }else if(nums[i]==2){
                swap(nums[e], nums[i]);
                e--;
                i--; //need to check whether swapped value is zero
            }
        }
    }
};