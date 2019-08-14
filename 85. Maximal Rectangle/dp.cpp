class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m, n;
        int maxArea = 0;
        
        m = matrix.size();
        if(m <=0) return maxArea;
        n = matrix[0].size();
        
        //row by row to caculate area.
        vector<int> left = vector<int>(n, 0);
        vector<int> right = vector<int>(n, n-1);
        vector<int> height = vector<int>(n, 0);
        
        for(int i=0; i<m; i++){
            
            int l = 0;
            int r = n-1;
            
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1'){
                    left[j] = max(left[j], l);
                }else{
                    left[j] = 0;
                    l = j+1;
                }
            }
            
            for(int j=n-1; j>=0; j--){
                if(matrix[i][j]=='1'){
                    right[j] = min(right[j], r);
                }else{
                    right[j] = n-1;
                    r = j-1;
                }
            }
            
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1') height[j]++;
                else height[j] = 0;
            }
            
            for(int j=0; j<n; j++){
                int area = (matrix[i][j]=='1')? height[j] * (right[j] - left[j] + 1) : 0;
                maxArea = max(maxArea, area);
            }
        }
        
        return maxArea;
    }
};