class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minBuy = INT_MAX;
        
        for(int i=0; i<prices.size(); i++){         
            if(i>0){
                profit = max(profit, prices[i] - minBuy);
            }
            
            minBuy = min(minBuy, prices[i]);
        }
        
        return profit;
    }
};