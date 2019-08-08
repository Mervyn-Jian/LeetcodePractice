class Solution {
public:
    bool isMatch(string s, string p) {
        bool** dp = new bool*[s.length()+1];
        
        for(int i=0; i<s.length()+1; i++){
            dp[i] = new bool[p.length()+1];
        }
        
        for(int i=0; i<s.length()+1; i++){
            for(int j=0; j<p.length()+1; j++){
                dp[i][j]=false;
            }
        }
        
        dp[s.length()][p.length()] = true;
        for(int j=p.length()-1; j>=0; j--){
            if(p[j]=='*'){
                dp[s.length()][j] = dp[s.length()][j+1];
            }else{
                break;
            }
        }
        
        for(int i=s.length()-1; i>=0; i--){
            for(int j=p.length()-1; j>=0; j--){
                if(p[j]=='*'){
                    dp[i][j] = (dp[i+1][j] || dp[i][j+1]);
                }else{
                    bool match = (p[j]==s[i]) || (p[j]=='?');
                    dp[i][j] = (match && dp[i+1][j+1]);
                }
            }
        }
        
        return dp[0][0];
    }
};