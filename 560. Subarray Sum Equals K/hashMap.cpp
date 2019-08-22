class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // subSum[i, j] = sum[0, j] - sum[0, i-1]
        // => k = sum[0, j] - sum[0, i-1]
        // => sum[0, i-1] = sum[0, j] - k, using hash map to record sum and count number
        
        unordered_map<int, int> sumMap;
        unordered_map<int, int>::iterator map_it;
        int count = 0;
        int sum = 0;
        
        sumMap.insert(pair<int, int>(0, 1));
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            
            if((map_it = sumMap.find(sum - k)) != sumMap.end()){
                count += map_it->second;
            }
            sumMap[sum]++;
        }
        
        return count;
    }
};