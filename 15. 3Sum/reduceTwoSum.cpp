class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++){
            int key = nums[i];
            
            if(key>0) break;
            if(i>0 && key==nums[i-1]) continue;
            
            vector<vector<int>> twoSumArr = twoSum(nums, i+1, -key);
            result.insert(result.end(), twoSumArr.begin(), twoSumArr.end());
            
        }
        return result;
    }
    
    vector<vector<int>> twoSum(vector<int>& nums, int s, int target){
        vector<vector<int>> result;
        int left=s;
        int right=nums.size()-1;
        
        while(left<right){ 
            int nl = nums[left];
            int nr = nums[right];
            int sum = nl+nr;
            
            if(sum==target){
                vector<int> re;
                re.push_back(-target);
                re.push_back(nl);
                re.push_back(nr);
                result.push_back(re);
                
                left++;
                while(left<right && nums[left]==nums[left-1]) left++;
                
            }else if(sum<target){
                left++;
            }else if(sum>target){
                right--;
            }
        }
  
        return result;
    }
};