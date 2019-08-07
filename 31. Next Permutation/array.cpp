class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1) return;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i+1]>nums[i]){
                int key=nums[i];
                for(int j=nums.size()-1; j>i; j--){
                    if(nums[j]>key){
                        swap(nums[j], nums[i]);
                        sort(nums.begin()+i+1, nums.end());
                        return;
                    }
                }
            }
        }
        
        sort(nums.begin(), nums.end());
    }

};