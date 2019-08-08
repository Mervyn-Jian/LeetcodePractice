class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()<=0) return 0;
        
        map<int,int> counts;
        
        for(int i=0; i<nums.size(); i++){
            counts[nums[i]]++;
        }
        
        map<int,int>::iterator it;
        int max = 0;
        int res = 0;
        for(it=counts.begin(); it!=counts.end(); it++){
            if(it->second>=max){
                max = it->second;
                res = it->first;
            }
        }
        
        return res;
    }
};