class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        if(triangle.size() <= 0) return INT_MAX;
        if(triangle.size() == 1) return triangle[0][0];
            
        int minTotal = INT_MAX;
        vector<vector<int>> dp;
        
        for(int i=0 ; i<triangle.size(); i++){
            dp.push_back(vector<int>());
            for(int j=0 ; j<triangle[i].size(); j++){
                dp[i].push_back(INT_MAX);
            }
        }
        
        dp[0][0] = triangle[0][0];
        for(int i=1; i<triangle.size(); i++){
            for(int j=0; j<=i; j++){
                
                if(j==0){
                    dp[i][j] = triangle[i][j] + dp[i-1][j];
                }else if(j == i){
                    dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                }else{
                    dp[i][j] = min(triangle[i][j] + dp[i-1][j-1], 
                                   triangle[i][j] + dp[i-1][j  ]);
                }
                
                if(i == triangle.size()-1){
                    minTotal = min(minTotal, dp[i][j]);
                }
            }
        }
        
        return minTotal;
    }
};