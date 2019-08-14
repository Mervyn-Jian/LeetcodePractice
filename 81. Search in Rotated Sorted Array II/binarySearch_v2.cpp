class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int left = 0;
        int right = n-1;
        
        while(left <= right){
            int mid = left + (right-left)/2;
            int nl = nums[left];
            int nr = nums[right];
            int nm = nums[mid];
            
            if(nums[mid] == target) return true;
            if(left == right) break;
            
            if(nl < nm ){
                if(target < nm && nl <= target){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else if(nr > nm){
                if(target > nm && nr >= target){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }else{            //worst case
                if(nm == nl) left++;
                if(nm == nr) right--;
            }
        }
        
        return false;
    }
};