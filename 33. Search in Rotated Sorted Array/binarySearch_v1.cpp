class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
        [0,1,2,4,5,6,7] -> [4,5,6,7,0,1,2]
        0 -> 4 
        3 -> 0
        i -> (i+4) % nums.size()
        pivot = 4th number, index=3
        */
        //find pivot
        int n=nums.size();
        int i=0;
        int j=n-1;
        int pivot = 0;
        while(i<j){
            int mid = (i+j)/2;
            
            if(j-i==1 && nums[i]>nums[j]){
                pivot=j;
                break;
            }
            
            if(nums[i]>nums[mid]){
                j=mid;
            }else if(nums[mid]>nums[j]){
                i=mid;
            }else if(nums[mid]==nums[i]){
                i=mid+1;
            }else if(nums[mid]==nums[j]){
                j=mid-1;
            }else{
                break;
            }
        }
        
        i=0;
        j=n-1;
        while(i<=j){
            int mid=(i+j)/2;
            int midVal = nums[(mid+pivot)%n];
            if(target==midVal) return (mid+pivot)%n;
            if(target>midVal){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return -1;
    }
};