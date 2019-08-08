class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()<=0) return INT_MIN;
        
        vector<int> dp = vector<int>(nums.size(), INT_MIN);
        int maxSub = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(i==0){ 
                dp[i] = nums[i];
            }else{
                dp[i] = nums[i] + max(dp[i-1], 0);
            }
            if(dp[i]>maxSub) maxSub=dp[i];
        }
        
        return maxSub;
    }
};