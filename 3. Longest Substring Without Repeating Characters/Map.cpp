using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 1;
        if(s.size()<=0) return 0;
        if(s.size()==1) return maxLen;
        
        map<char, int> alphas;
        
        alphas.insert(pair(s[0], 0));
        int len = 1;

        int i=1;
        map<char, int>::iterator it;
        while(i<s.size()){
            
            it = alphas.find(s[i]);
            if(it!=alphas.end()){
                int nxtIdx = it->second+1;
                alphas.clear();
                
                len=1;
                alphas.insert(pair(s[nxtIdx], nxtIdx));
                i = nxtIdx+1;
            }else{
                len++;
                alphas.insert(pair(s[i], i));
                i++;
            } 
            
            if(len>maxLen) maxLen = len;
        }
        
        return maxLen;
    }
   
};