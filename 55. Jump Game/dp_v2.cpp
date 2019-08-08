class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp = vector<bool>(nums.size(), false);
        if(nums.size()<=0) return false;
        
        dp[0] = true;
        for(int i=1; i<nums.size(); i++){
            for(int j=i-1; j>=0; j--){ 
                if(dp[j]==true){
                    if(j+nums[j]>=i){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[nums.size()-1];
    }
};