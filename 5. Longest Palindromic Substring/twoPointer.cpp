class Solution {
public:
    
    string longestPalindrome(string s) {
        string maxLp = "";
        int n = s.size();
        int left;
        int right;
        
        for(int i=0; i<n; i++){
            left = i;
            right = i;
            
            while( right+1<n && s[right]==s[right+1]){
                right = right+1;
            }
            
            while(left-1>=0 && right+1<n && s[left-1]==s[right+1]){
                left = left-1;
                right = right+1;
            }
            
            if(right-left+1 > maxLp.size()){
                maxLp = s.substr(left, right-left+1);
            }
        }
        
        return maxLp;
    }
    
};