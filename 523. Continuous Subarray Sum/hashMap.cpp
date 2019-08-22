class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // subSum[i, j] = sum[0, j] - sum[0, i-1]
        // => kn = sum[0, j] - sum[0, i-1]
        // =>  0 = sum[o, j]%k - sum[0, i-1]%k
        // =>  sum[0, i-1]%k = sum[o, j]%k, using hash map to record sum and index number
        
        unordered_map<int, int> sumMap;
        unordered_map<int, int>::iterator map_it;
        int sum = 0;
        
        sumMap.insert(pair<int, int>(0, -1));  //initialization location
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(k != 0) sum = sum % k;
            if((map_it = sumMap.find(sum)) != sumMap.end()){
                int preSumIndex = map_it->second;
                if( i - preSumIndex >=2 ) return true;
            }else{
                sumMap[sum] = i;
            }
        }
        
        return false;
    }
};