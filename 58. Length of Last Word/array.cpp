class Solution {
public:
    int lengthOfLastWord(string s) {
        int backStart=s.size()-1;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]==' ') continue;
            else{
                backStart = i;
                break;
            }
        }
        
        int len = 0;
        for(int i=backStart; i>=0; i--){
            if(s[i]==' ') break;
            else len++;
        }
        
        return len;
    }
};