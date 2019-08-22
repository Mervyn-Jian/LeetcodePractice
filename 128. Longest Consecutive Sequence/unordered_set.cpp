class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestSeq = 0;
        unordered_set<int> numSet;
        for(int i=0; i<nums.size(); i++){
            numSet.insert(nums[i]);
        }
        
        unordered_set<int>::iterator n_it = numSet.begin();
        for(; n_it != numSet.end(); n_it++){
            int cur = *n_it;
            int seq;
            if(numSet.find(cur-1) == numSet.end()){
                seq = 1;
                while(numSet.find(cur+1) != numSet.end()){
                    cur = cur + 1;
                    seq++;
                }
                
                longestSeq = max(longestSeq, seq);
            }
        }
        
        return longestSeq;
    }
};