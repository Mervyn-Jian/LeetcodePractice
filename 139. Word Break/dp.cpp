class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp = vector<bool>(s.size(), false);
        
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<=i; j++){
                if(j==0 || (j-1 >= 0 && dp[j-1] == true) ){
                    string str = s.substr(j, i-j+1);
                    if(find(wordDict.begin(), wordDict.end(), str) != wordDict.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[s.size()-1];
    }
};