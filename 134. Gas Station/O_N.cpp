class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // gas - cost = residual tank gas
        // if sum of residual gas is positive, thers is an answer.
        // => check positive gas station index as starting point
        int tank = 0;
        int start = 0;
        int totalCost = 0;
        for(int i=0; i<cost.size(); i++){
            tank += gas[i];
            tank -= cost[i];
            
            if(tank < 0){
                start = i+1;
                totalCost += tank;
                tank = 0;
            }
        }
        totalCost += tank;
        
        return (totalCost>=0)? start : -1;
    }
};