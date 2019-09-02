class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        
        for(int i=0; i<32; i++){
            int bitCount = 0;
            int bit = 1<<i;
            for(int j=0; j<nums.size(); j++){
                if((nums[j] & bit) != 0) bitCount++;
            }
            
            if(bitCount % 3 != 0) num |= bit;
        }
        
        return num;
    }
};