class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> shortHeightIdxes;
        int i=0;
        int maxArea = 0;
        
        while(i<heights.size()){
            if(shortHeightIdxes.empty() || heights[i]>=heights[shortHeightIdxes.top()]){
                shortHeightIdxes.push(i);
                i++;
            }else{
                int shortHeightIdx = shortHeightIdxes.top();
                shortHeightIdxes.pop();
                
                int shortHeight = heights[shortHeightIdx];
                int width = shortHeightIdxes.empty()? i : i - shortHeightIdxes.top() - 1;
                int area = shortHeight * width;
                
                maxArea = max(maxArea, area);
            }
        }
        
        while(!shortHeightIdxes.empty()){
            int shortHeightIdx = shortHeightIdxes.top();
            shortHeightIdxes.pop();
            
            int shortHeight = heights[shortHeightIdx];
            int width = shortHeightIdxes.empty()? i : i - shortHeightIdxes.top() - 1;
            int area = shortHeight * width;
                
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};