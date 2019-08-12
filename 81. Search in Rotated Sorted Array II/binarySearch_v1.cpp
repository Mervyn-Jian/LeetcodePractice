class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int pivot = 0;
        int n = nums.size();
        int left = 0;
        int right = n-1;
        bool worstCase = false;
        
        //find minimum number index
        while(left < right){
            int mid = left + (right-left)/2;
            int nl = nums[left];
            int nr = nums[right];
            int nm = nums[mid];
            
            if(right-left == 1 && nums[left] > nums[right]){
                pivot = right;
                break;
            }
            
            if(nm < nl) right = mid;
            else if(nm > nr) left = mid;
            else if(nm == nl && nm == nr){    //worst case
                worstCase = true;
                break;
            }else break;
        }
        
        if(worstCase){
            for(int i=left; i<right; i++){
                if(nums[i] > nums[i+1]){ 
                    pivot = i+1;
                }
            }
        }
        
        //binary search
        left = 0;
        right = n-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            int nm = nums[ (mid+pivot) % n ];
            
            if(nm == target) return true;
            else if(nm > target) right = mid -1;
            else if(nm < target) left = mid + 1;
        }
        
        return false;
    }
};