class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int shortestLen = INT_MAX;
        string result = "";
        
        if(strs.size()<=0) return result;
        
        for(int i=0; i<strs.size(); i++){
            int len = strs[i].size();
            
            if(len==0) return result;
            if(len<shortestLen){
                shortestLen = len;
            }
        }
        
        int lastIndx = -1;
        bool end = false;
        for(int i=0; i<shortestLen; i++){
            
            char ch = strs[0][i];
            for(int j=1; j<strs.size(); j++){
                if(ch != strs[j][i]){
                    end=true;
                    break;
                }
            }
            if(end) break;
            lastIndx = i;
        }
        
        return strs[0].substr(0, lastIndx+1);
    }
};

