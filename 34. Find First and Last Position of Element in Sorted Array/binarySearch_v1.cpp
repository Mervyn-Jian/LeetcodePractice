class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n=nums.size();
        int i=0;
        int j=n-1;
        int min=-1;
        int max=n;
        
        //binary search minimum
        while(i<j){
            int mid=(i+j)/2;
            
            if(nums[mid]<target && (mid+1<n-1 && nums[mid+1]>=target)){
                min=mid;
                break;
            }else if(nums[mid]<target){
                i=mid+1;
            }else if(nums[mid]>=target){
                j=mid-1;
            }
        }
        if(i==j && nums[i]<target && min==-1) min=i;
        else if(i==j && nums[i]==target && i-1>=0 && min==-1) min=i-1;
            
        //binary search maximum
        i=0;
        j=n-1;
        while(i<j){
            int mid=(i+j)/2;
            
            if(nums[mid]>target && (mid-1>=0 && nums[mid-1]<=target)){
                max=mid;
                break;
            }else if(nums[mid]>target){
                j=mid-1;
            }else if(nums[mid]<=target){
                i=mid+1;
            }
        }
        if(i==j && nums[i]>target && max==n) max=i;
        else if(i==j && nums[i]==target && i+1<n && max==-1) max=i+1;
              
        vector<int> re;
        if(min+1<n && nums[min+1]==target){
            re.push_back(min+1);
        }else{
            re.push_back(-1);
        }

        if(max-1>=0 && nums[max-1]==target){
            re.push_back(max-1);
        }else{
            re.push_back(-1);
        }

        return re;
        
    }
};