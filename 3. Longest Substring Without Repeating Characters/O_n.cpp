using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen =0;
        int left=0, right=0;
        set<char> alphas;
        
        while(left<s.size()){
            if(alphas.find(s[left])!=alphas.end()){
                alphas.erase(s[right]);
                right++;
            }else{
                alphas.insert(s[left]);
                left++;
                maxLen = max(maxLen, left-right);
            }
        }
        
        return maxLen;
    }
   
};