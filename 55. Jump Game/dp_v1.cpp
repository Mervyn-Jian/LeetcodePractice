class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<= 0) return false;
        if(nums.size()== 1) return true;
        
        //record the number of jumps
        vector<int> dp = vector<int>(nums.size(), 0);
        
        for(int i=1; i<nums.size(); i++){
            int minJump = INT_MAX;
            int minSlot = INT_MAX;
            for(int j=i-1; j>=0; j--){
                int dist = i-j;                
                
                if(nums[j]>= dist){
                    minJump = min(dist, minJump);
                    minSlot = j;
                }
            }
            
            if(minJump!=INT_MAX && minSlot==0){
                dp[i] = 1;
            }
            
            if(minJump!=INT_MAX && dp[minSlot] >0 && minSlot!=0){
                dp[i] = dp[minSlot]+1;
            }
        }
        
        //for(auto i:dp) cout<<i<< " ";
        
        return dp[nums.size()-1] >0;
    }
};