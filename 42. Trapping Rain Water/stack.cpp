class Solution {
public:
    int trap(vector<int>& height) {
        
        int rain = 0;
        vector<int> stack;
        
        for(int i=0; i<height.size(); i++){
            while(stack.size()>0 && height[i]>height[stack.back()]){
                int holeHeight = height[stack.back()];
                stack.pop_back();
                
                if(stack.size()<=0) break;
                else{
                    int leftBarrier = height[stack.back()];
                    rain += (min(height[i], leftBarrier)-holeHeight)*(i-stack.back()-1);
                }
            }
            stack.push_back(i);
        }
        
        return rain;
    }
};