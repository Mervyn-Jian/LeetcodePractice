class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largest = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            int sum = nums[i];
            largest = max(sum, largest);
            for(int j=i+1; j<nums.size(); j++){
                sum += nums[j];
                largest = max(sum, largest);
            }
        }
        
        return largest;
    }
};