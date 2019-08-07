#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.size()<=1) return result;
        
        map<int, int> numMap;
        
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            int key = target - num;
            
            if(numMap.find(key) != numMap.end()){
                result.push_back(numMap[key]);
                result.push_back(i);
            }else{
                numMap[num] = i;
            }
        }
        
        return result;
        
    }
};