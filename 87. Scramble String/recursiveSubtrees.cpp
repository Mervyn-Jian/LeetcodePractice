class Solution {
public:
    bool isScramble(string s1, string s2) {
        //reduce problem into flip equavalent binary tree
        //iterate all sub-string cut to generate subtrees
        if(s1.size() != s2.size()) return false;
        else if(s1 == "" && s2 == "") return true;
        else if(s1 == "" || s2 == "") return false;
        else if(s1 == s2) return true;
        
        string sortS1 = s1;
        string sortS2 = s2;
        sort(sortS1.begin(), sortS1.end());
        sort(sortS2.begin(), sortS2.end());
        
        if(sortS1==sortS2){
            for(int i=1; i<s1.size(); i++){
                bool case1 = isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, s1.size()-i), s2.substr(i, s2.size()-i));
                
                if(case1) return true;
                
                bool case2 = isScramble(s1.substr(0, i), s2.substr(s2.size()-i, i)) && isScramble(s1.substr(i, s1.size()-i), s2.substr(0, s2.size()-i));
                
                if(case2) return true;
            }
        }
        
        return false;
    }
};