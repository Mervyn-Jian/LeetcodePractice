class Solution {
public:
    string getPermutation(int n, int k) {
        
        if(n<=0 || k<=0) return "";
        int total=1;
        for(int i=1; i<=n; i++){
            total *= i;
        }
        total = (n==0)? 0:total;
        if(k>total) return "";
        
        set<char> numSet;
        vector<int> nums = vector<int>(n, 0);
        string s="";
        string res="";
        int count=0;
        
        if(k<= total/2){
            for(int i=0; i<nums.size(); i++){
                nums[i] = (i+1)+'0';
            }
            backtrack(count, k, s, res, nums, numSet);
        }else{
            for(int i=nums.size(); i>0; i--){
                nums[nums.size()-i] = i+'0';
            }
            backtrack(count, total-k+1, s, res, nums, numSet);
        }
        return res;
    }
    
    void backtrack(int &count, int k, string &s, string &res, vector<int> &nums, set<char> &numSet){
        if(s.size()==nums.size()){
            count++;
            if(k==count) res=s;
            
            return;
        }
        if(count>=k) return;
        
        for(int i=0; i<nums.size(); i++){
            char ch = nums[i];
            if(numSet.find(ch)==numSet.end()){
                s+=ch;
                numSet.insert(ch);
                
                backtrack(count, k, s, res, nums, numSet);
                if(count>=k) return;
                
                s=s.substr(0, s.size()-1);
                numSet.erase(ch);
            }
        }
    }
};