class Solution {
public:
    bool isPalindrome(string s) {
        string sStrip;
        for(int i=0; i<s.size(); i++){
            if(s[i]>='a' && s[i]<='z') sStrip.push_back(s[i]);
            if(s[i]>='A' && s[i]<='Z') sStrip.push_back(tolower(s[i]));
            if(s[i]>='0' && s[i]<='9') sStrip.push_back(s[i]);
        }
        
        for(int i=0; i<sStrip.size()/2; i++){
            if(sStrip[i] != sStrip[sStrip.size()-1-i]) return false;
        }
        
        return true;
    }
};