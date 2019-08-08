class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()<=0) return -1;
        
        int minIdx = binary_search_min(nums, 0, nums.size()-1);
        
        int seg0Idx = binary_search(nums, target, 0, minIdx-1);
        int seg1Idx = binary_search(nums, target, minIdx, nums.size()-1);
        
        return seg0Idx>seg1Idx? seg0Idx:seg1Idx;
    }
    
    int binary_search_min(vector<int>& nums,int start,int end){
        if(start>=end) return end;
        
        int midIdx = (start+end)/2;
        int mid = nums[midIdx];
        
        if(mid>nums[end]) return binary_search_min(nums, midIdx+1, end);
        
        return binary_search_min(nums, start, midIdx);
    }
    
    int binary_search(vector<int>& nums, int target,int start,int end){
        if(start>end) return -1;
        
        int midIdx = (start+end)/2;
        int mid = nums[midIdx];
        
        if(target == mid) return midIdx;
        
        if(target > mid) return binary_search(nums, target, midIdx+1, end);
        
        return binary_search(nums, target, start, midIdx-1);
    }
};