class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m, n;
        int maxArea = 0;
        
        m = matrix.size();
        if(m <=0) return maxArea;
        n = matrix[0].size();
        
        //reduce the problem into two-dimensional largest rectangle
        //row by row to caculate area.
        vector<int> height = vector<int>(n, 0);
        stack<int> shortLeft;
        
        for(int i=0; i<m; i++){
            
            for(int k=0;k<n; k++){
                if(matrix[i][k]=='1') height[k]++;
                else height[k] = 0;
            }
            
            int j=0;
            while(j<n){
                if(shortLeft.empty() || height[j] >= height[shortLeft.top()]){
                    shortLeft.push(j);
                    j++;
                }else{
                    int shortHeight = height[shortLeft.top()];
                    shortLeft.pop();
                    int width = shortLeft.empty()? j : j-shortLeft.top()-1;
                    int area = shortHeight * width;

                    maxArea = max(maxArea, area);
                }
            }
        
            while(!shortLeft.empty()){
                int shortHeight = height[shortLeft.top()];
                shortLeft.pop();
                int width = shortLeft.empty()? j : j-shortLeft.top()-1;
                int area = shortHeight * width;

                maxArea = max(maxArea, area);
            }
        }
        
        return maxArea;
    }
};