class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        if(triangle.size() <= 0) return INT_MAX;
            
        vector<int> dp = vector<int>(triangle.back());
        
        //bottom up => end the only endpoint triangle[0][0];
        for(int i=triangle.size()-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        
        return dp[0];
    }
};