class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        
        int j=0;
        int i=1;
        int count =1;
        int curNum = nums[j];
        while(i < n){
            
            if(nums[i] > curNum){
                j++;
                curNum = nums[i];
                count = 1;
                swap(nums[j], nums[i]);
                i++;
            }else if(count<2){
                if(nums[i] == curNum){
                    count++;
                    j++;
                    swap(nums[j], nums[i]); // i may be not adjacent to j
                    i++;
                }else if(nums[i] < curNum){
                    i++;
                }
            }else if(count >=2){
                if(nums[i] <= curNum){
                    i++;
                }
            }
        }
        
        return j+1;
    }
};