class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        
        for(int i=0; i<height.size(); i++){
            for(int j=i+1; j<height.size(); j++){
                int area = min(height[j], height[i])*(j-i);
                if(area>maxA) maxA = area;
            }
        }
        
        return maxA;
    }
};