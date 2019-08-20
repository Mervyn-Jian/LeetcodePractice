class Solution {
public:
    int numTrees(int n) {
        if(n<0) return 0;
        
        // dp[i] is number of trees that number of node is i
        /*
        example: 
        n=3
        dp = [1 1 2 5]
        
        // sum of combination of product number of left tree and right tree
        i=1: dp[0] * dp[0]

        i=2: dp[0] * dp[1] +
             dp[1] * dp[0]

        i=3: dp[0] * dp[2] +
             dp[1] * dp[1] +
             dp[2] * dp[0]

        i=4: dp[0] * dp[3] +
             dp[1] * dp[2] +
             dp[2] * dp[1] +
             dp[3] * dp[0]
        */
        
        vector<int> dp = vector<int>(n+1, 0);
        
        dp[0] = 1; //null tree
        for(int i=1; i<=n; i++){
            for(int j=i-1; j>=0; j--){
                dp[i] += dp[j] * dp[(i-1)-j]; 
            }
        }
        
        return dp[n];
    }
};