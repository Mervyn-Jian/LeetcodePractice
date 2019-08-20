class Solution {
public:
    bool isScramble(string s1, string s2) {
        // reduce problem into flip equavalent binary tree
        // iterate all sub-string cut to generate subtrees
        // dp[length][i][j] represents whether 
        // s1[i...length-1+i] is scramble string of s2[j...length-1+j]
        int length = s1.size();
        bool dp[length+1][length][length];
        
        for(int l=0; l<length+1; l++){
            for(int i=0; i<length; i++){
                for(int j=0; j<length; j++){
                    if(l==0){
                        dp[l][i][j] = true;
                    }else{
                        dp[l][i][j] = false;
                    }
                }
            }
        }
        
        for(int i=0; i<length; i++){
            for(int j=0; j<length; j++){
                dp[1][i][j] = (s1[i] == s2[j]);
            }
        }
        
        for(int l = 2; l<=length; l++){
            for(int i=0; i<=length-l; i++){
                for(int j=0; j<=length-l; j++){
                    for(int k=1; k<l; k++){
                        dp[l][i][j] = dp[l][i][j] || (dp[k][i][j] && dp[l-k][i+k][j+k]);
                        dp[l][i][j] = dp[l][i][j] || (dp[k][i][j+(l-k)] && dp[l-k][i+k][j]);
                        
                        if(dp[l][i][j] == true) break;
                    }
                }
            }
        }

        return dp[length][0][0];
    }
};