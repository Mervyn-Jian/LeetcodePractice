class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDist=INT_MAX;
        int ans = INT_MAX;
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            int key = nums[i];
            if(i>0 && key==nums[i-1]) continue;
            
            int search = target-key;
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                int sum = nums[right]+nums[left];
                int distance = abs(search-sum);
          
                if(distance<minDist){
                    minDist = distance;
                    ans = sum+key;
                }
                
                if(sum==search){
                    while(left+1<nums.size() && nums[left]==nums[left+1]) left++;
                    while(right>i
                          +1 && nums[right]==nums[right-1]) right--;
                    left++;
                    right--;
                }else if(sum<search){
                    left++;
                }else if(sum>search){
                    right--;
                }
            }
        }
        return ans;
    }
};