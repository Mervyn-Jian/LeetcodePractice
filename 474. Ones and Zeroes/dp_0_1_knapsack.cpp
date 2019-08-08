class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if(strs.size()<=0) return 0;
        
        int** dp = new int*[m+1];
        for(int i=0; i<m+1; i++){
            dp[i] = new int[n+1];
        }
        
        for(int i=0; i<m+1; i++){
            for(int j=0; j<n+1; j++){
                dp[i][j] = 0;
            }
        }
        
        for(int i=0; i<strs.size(); i++){
            string str = strs[i];
            int zero=0;
            int one=0;
            
            for(int j=0; j<str.size(); j++){
                if(str[j]=='0') zero++;
                if(str[j]=='1') one++;
            }
            
            for(int j=m; j>=0; j--){
                for(int k=n; k>=0; k--){
                    if(j>=zero && k>=one){
                        dp[j][k] = max(dp[j][k], 1+dp[j-zero][k-one]);
                    }else{
                        dp[j][k] = dp[j][k];
                    }
                }
            }
        }
        
        return dp[m][n];
    }

};