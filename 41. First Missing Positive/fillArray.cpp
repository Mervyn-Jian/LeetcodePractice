class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //place right value to its index, 1 -> 0, 2 -> 1 etc...
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=0) continue;
            else{
                while(true){
                    int index = nums[i]-1;
                    
                    if(nums[i]<=0) break;
                    if(index==i) break;
                    if(index<nums.size()){
                        if(nums[index]==nums[i]) break;
                        swap(nums[index], nums[i]);
                    }else{
                        break;
                    }
                }
            }
        }
        
        int wrongIndex=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==i+1){ 
                wrongIndex++;
            }else{
                wrongIndex = i;
                break;
            }
        }
        
        return wrongIndex+1;
    }
};