class Solution {
public:
    int jump(vector<int>& nums) {
        
        int jump=0;
        int farestPos = 0;
        int jumpPos = 0;
        
        for(int i=0; i<nums.size()-1; i++){           
            
            int pos = nums[i];
            if(i+pos>farestPos){
                farestPos = i+pos;
            }
            
            if(i==jumpPos){
                jump++;
                jumpPos = farestPos;
            }
        }
        return jump;
    }
};
