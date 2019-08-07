class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack==needle) return 0;
        int needleLen = needle.length();
        if(needleLen > haystack.length()) return -1;
        
        for(int i=0; i<haystack.length()-needleLen+1; i++){
            string sub = haystack.substr(i, needleLen);
            if(sub==needle) return i;
        }
        return -1;
    }
};