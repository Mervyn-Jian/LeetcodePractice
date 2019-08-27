class Solution {
public:
    int minCut(string s) {
        // dp[i] is minimum cut that string s[0:i]
        // default values of dp are cutting at every alphabet.
        // ex: 0 1 2 3 4 5 6 7
        //     a b c b b b c a 
        //           j   i
        // if dp[0]~dp[4] is computed.
        // dp[5] = dp[2] + 1 => iterate j find minimum, j = 3
        //                   => from j=0 to i, if s[j:i] is palindrome 
        if(s.size() <= 0) return 0;
        vector<int> dp = vector<int>(s.size());
        
        for(int i=0; i<dp.size(); i++){
            dp[i] = i;
        }
        
        for(int i=1; i<dp.size(); i++){
            int minCut = dp[i];
            for(int j=0; j<=i; j++){
                string str = s.substr(j, i-j+1);
                if(isPalindrome(str)){
                    if(j-1 >= 0) minCut = min(dp[j-1]+1, minCut);
                    else minCut = min(0, minCut);
                }
                dp[i] = minCut;
            }
        }
        
        return dp[s.size()-1];
    }
    
    bool isPalindrome(string &str){
        int left = 0;
        int right = str.size()-1;
        while(left < right){
            if(str[left] == str[right]){
                left++;
                right--;
            }else{
                return false;
            }
        }
        
        return true;
    }
};