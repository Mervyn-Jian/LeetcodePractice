class Solution {
public:
    string getPermutation(int n, int k) {
        
        if(n<=0 || k<=0) return "";
        vector<int> factor=vector<int>(n+1, 1);
        for(int i=2; i<n+1; i++){
            factor[i] = factor[i-1]*i;
        }
        if(k>factor[factor.size()-1]) return "";
        
        vector<int> nums = vector<int>(n, 0);
        string res="";
        for(int i=0; i<nums.size(); i++){
            nums[i] = (i+1)+'0';
        }
        
        k--;
        for(int i=n; i>0; i--){
            int numIndex = k / factor[i-1];
            res += nums[numIndex];
            k = k % factor[i-1];
            nums.erase(nums.begin()+numIndex);
        }
            
        return res;
    }
    
};