class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size()+1;
        int allSum = ((n-1+0)*n)/2;
        int sum = 0;
        
        for(int num:nums) sum += num;
        return allSum - sum;
    }
};