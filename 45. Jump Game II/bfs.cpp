class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        
        //bfs to last position
        int jumpCount=0;
        int farest = nums[0];
        int cur = 0;
        
        while(farest-cur>0){ //there are positions after current pos
            jumpCount++;
            if(farest>=nums.size()-1) break;
            
            int nextFarset=farest;
            while(cur<farest){
                nextFarset = max(nums[cur+1]+cur+1,nextFarset);
                cur++;
            }
            
            farest=nextFarset;
        }
        
        return jumpCount;
    }
};
