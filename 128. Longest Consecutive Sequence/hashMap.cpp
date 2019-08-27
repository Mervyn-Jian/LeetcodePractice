class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestSeq = 0;
        unordered_map<int, int> numSeq;
        
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            if(numSeq.find(num) == numSeq.end()){
                int leftSeq = (numSeq.find(num-1) == numSeq.end())? 0 : numSeq[num-1];
                int rightSeq = (numSeq.find(num+1) == numSeq.end())? 0 : numSeq[num+1];
                int seq = leftSeq + 1 + rightSeq;
                
                numSeq[num] = seq;
                if(leftSeq > 0) numSeq[num-leftSeq] = seq;
                if(rightSeq > 0) numSeq[num+rightSeq] = seq;
                
                longestSeq = max(longestSeq, seq);
            }
        }
        
        return longestSeq;
    }
};