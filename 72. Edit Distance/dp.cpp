class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1 = word1.size();
        int w2 = word2.size();
        vector<vector<int>> dp = vector<vector<int>>(w1+1, vector<int>(w2+1, 0));
        
        for(int i=1; i<=w1; i++){
            dp[i][0] = i;
        }
        
        for(int i=1; i<=w2; i++){
            dp[0][i] = i;
        }
        
        for(int i=1; i<=w1; i++){
            for(int j=1; j<=w2; j++){
                //current character is the same (dp index is different from word index)
                if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(min(dp[i][j-1]+1, dp[i-1][j]+1), dp[i-1][j-1]+1);
            }
        }
        
        return dp[w1][w2];
    }
};