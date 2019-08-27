class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // gas - cost = residual tank gas
        // if sum of residual gas is positive, thers is an answer.
        // => check positive gas station index as starting point
        for(int i=0; i<gas.size(); i++){
            cost[i] = gas[i] - cost[i];
        }
        
        for(int i=0; i<cost.size(); i++){
            int travel;
            int tank;
            if(cost[i] >= 0){
                travel = i;
                tank = cost[i];
            }else{
                continue;
            }
            
            while(tank >=0 ){
                travel = (travel+1) % cost.size();
                tank += cost[travel];
                if(travel == i) return travel;
            }
        }
        
        return -1;
    }
};