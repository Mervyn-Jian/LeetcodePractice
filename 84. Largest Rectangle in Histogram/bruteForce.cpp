class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int maxArea = 0;
        for(int i=0; i<heights.size(); i++){
            
            int height = heights[i];
            for(int j=i; j<heights.size(); j++){
                int area;
                if(heights[j] < height) height = heights[j];
                
                area = height * (j-i+1);
                if(area > maxArea) maxArea = area;
            }
        }
        
        return maxArea;
    }
};