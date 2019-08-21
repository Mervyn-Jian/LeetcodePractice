class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        for(int i=0; i<prices.size(); i++){
            int buyPrice = prices[i];
            for(int j=i+1; j<prices.size(); j++){
                int sellPrice = prices[j];
                if(sellPrice > buyPrice){
                    profit = max(profit, sellPrice - buyPrice);
                }
            }
        }
        
        return profit;
    }
};