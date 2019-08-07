class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int left =0;
        int right = height.size()-1;
        
        while(left<right){
            int area = (right-left)*min(height[right], height[left]);
            if(area>maxA) maxA=area;
            
            if(height[right]<height[left]){
                right-=1;
            }else{
                left+=1;
            }
            
        }
        
        return maxA;
    }
};