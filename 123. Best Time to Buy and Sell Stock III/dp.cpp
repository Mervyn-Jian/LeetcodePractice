class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][j], i is ith transaction form 0 to 2
        // dp[i][j] is the profit of day j with ith transation
        // dp[i][j] = max(dp[i][j-1],   //stock did not be sold at day j.
        //                prices[j] - prices[k] + dp[i-1][k-1]);
        // where (prices[k] - dp[i-1][k-1]) is minimum that k's range is 0 to j-1
        // base case: profit of day 0 is zero. thereis not stock to be sold.
        //            profit of day 1 is profit of day 0 or profit earned by stock bought on day 0 
        
        int n = prices.size();
        if(n <= 0) return 0;
        
        int optimalProfit =0;
        vector<vector<int>> dp = vector<vector<int>>(3, vector<int>(n, 0));
        
        for(int i=1; i<dp.size(); i++){
            int minBudget; 
            for(int j=1; j<dp[i].size(); j++){
                if(j>1) minBudget = min(minBudget, prices[j-1] - dp[i-1][j-2]);
                else minBudget = prices[0];
                
                dp[i][j] = max(dp[i][j-1], prices[j] - minBudget);
                optimalProfit = max(optimalProfit, dp[i][j]);
            }
        }
        
        return optimalProfit;
    }
};