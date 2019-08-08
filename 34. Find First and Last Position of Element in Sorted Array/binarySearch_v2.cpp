class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()<=0) return vector<int>({-1,-1});
        
        int firstMatch = binary_search(nums, target, 0, nums.size()-1);
        
        if(firstMatch==-1) return vector<int>({-1,-1});
        
        int minIdx = firstMatch;
        int maxIdx = firstMatch;
        int curMinIdx = minIdx;
        int curMaxIdx = maxIdx;

        //cout<<maxIdx<<",  "<<minIdx<<endl;
        
        while(curMaxIdx>=0){
            if(curMaxIdx>maxIdx) maxIdx = curMaxIdx;
            curMaxIdx = binary_search(nums, target, curMaxIdx+1, nums.size()-1);
            
            //cout<<curMaxIdx<<", ";
        }
        //cout<<maxIdx<<endl;
        
        while(curMinIdx>=0){
            if(curMinIdx<minIdx) minIdx = curMinIdx;
            curMinIdx = binary_search(nums, target, 0, curMinIdx-1);
            //cout<<curMinIdx<<", ";
        }
        //cout<<minIdx<<endl;
        
        
        
        return vector<int>({minIdx,maxIdx});
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