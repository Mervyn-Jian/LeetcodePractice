class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bitAppearOnce = 0;
        int bitAppearTwice = 0;
        int bitAppearTreeTimes = 0;
        
        for(int i=0; i<nums.size(); i++){
            bitAppearTwice |= bitAppearOnce & nums[i];
            bitAppearOnce ^= nums[i];
            
            bitAppearTreeTimes = bitAppearOnce & bitAppearTwice;
            
            //clear bit;
            bitAppearOnce &= ~bitAppearTreeTimes;
            bitAppearTwice &= ~bitAppearTreeTimes;
        }
        
        return bitAppearOnce;
    }
};