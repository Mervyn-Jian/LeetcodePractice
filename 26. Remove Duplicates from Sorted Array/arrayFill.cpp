class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int duplicate=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]){
                duplicate++;
            }else{
                nums[i-duplicate] = nums[i];
            }
        }
        
        return nums.size()-duplicate;
    }
};