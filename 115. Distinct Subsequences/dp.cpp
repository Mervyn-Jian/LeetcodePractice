class Solution {
public:
    int numDistinct(string s, string t) {
        unsigned int dp[t.length()+1][s.length()+1];
        
        //initialization
        for(int i=0; i<=t.length(); i++){
            for(int j=0; j<=s.length(); j++){
                dp[i][j] = 0;
            }
        }
        
        //when t is empty syring, all combination number is one.
        for(int j=0; j<=s.length(); j++){
            dp[0][j] = 1;
        }
        
        for(int i=1; i<=t.length(); i++){
            for(int j=1; j<=s.length(); j++){
                if(t[i-1] == s[j-1]){
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        
        return static_cast<int>(dp[t.length()][s.length()]);
    }
};