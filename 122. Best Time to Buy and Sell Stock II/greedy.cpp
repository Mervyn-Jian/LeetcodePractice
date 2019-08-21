class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        //earn every profit greedily
        for(int i=1; i<prices.size(); i++){
            int pro = prices[i]-prices[i-1];
            profit += (pro > 0)?  pro : 0;
        }
        
        return profit;
    }
};