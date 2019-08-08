class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int rain = 0;
        if(n<=0) return rain;
        
        vector<int> leftBarrier = vector<int>(n, 0);
        vector<int> rightBarrier = vector<int>(n, 0);
        
        leftBarrier[0] = height[0];
        for(int i=1; i<n-1; i++){
            leftBarrier[i] = max(leftBarrier[i-1], height[i]);
        }
        
        rightBarrier[n-1] = height[n-1];
        for(int i=n-2; i>0; i--){
            rightBarrier[i] = max(rightBarrier[i+1], height[i]);
        }
        
        for(int i=1; i<n-1; i++){
            rain += min(rightBarrier[i], leftBarrier[i])-height[i];
        }
        
        return rain;
    }
};