class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n<=0) return 0;
        
        vector<int> dp = vector<int>(n, 0);
        
        dp[0] = (s[0]=='0')? 0 : 1;
        for(int i=1; i<n; i++){
            string twoDigits = "";
            int code;
            
            twoDigits += s[i-1];
            twoDigits += s[i];
            code = stoi(twoDigits);
            
            if(s[i] == '0'){
                dp[i] = 0;
            }else{
                dp[i] = dp[i-1];
            }
            
            //excluding zero heading number (I think it is weird.)
            if(code <=26 && code > 0 && s[i-1] != '0'){
                if(i>=2){
                    dp[i] += dp[i-2];
                }else{
                    dp[i] += 1;
                }
            }
        }
        
        return dp[n-1];
    }
};