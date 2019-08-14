class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n<=0) return 0;
        
        int maxArea = 0;
        vector<int> leftIndexes = vector<int>(n);
        vector<int> rightIndexes = vector<int>(n);
        
        leftIndexes[0] = -1;
        rightIndexes[n-1] = n;
        
        //fill left index
        for(int i=1; i<n; i++){
            int j = i-1;
            while(j>=0 && heights[j] >= heights[i]){
                j = leftIndexes[j];
            }
            leftIndexes[i] = j;
        }
        
        //fill right index
        for(int i=n-2; i>=0; i--){
            int j = i+1;
            while(j<n && heights[j] >= heights[i]){
                j = rightIndexes[j];
            }
            rightIndexes[i] = j;
        }
        
        for(int i=0; i<n; i++){
            int width = rightIndexes[i] - leftIndexes[i] -1;
            int area = heights[i] * width;
            
            maxArea = max(area, maxArea);
        }
        
        return maxArea;
    }
};