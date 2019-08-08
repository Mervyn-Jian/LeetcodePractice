class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string, vector<string>> strMap;
        
        /*
        vector<string> uniqueStrs;
        vector<string>::iterator uit;
        
        uniqueStrs = vector<string>(strs.begin(), strs.end());
        for(int i=0; i<uniqueStrs.size(); i++){
            sort(uniqueStrs[i].begin(), uniqueStrs[i].end());
        }
        uit = unique(uniqueStrs.begin(), uniqueStrs.end());
        uniqueStrs.resize( distance(uniqueStrs.begin(), uit) );
        
        for(int i=0; i<uniqueStrs.size(); i++){
            vector<string> vec;
            strMap.insert(pair<string, vector<string>>(uniqueStrs[i], vec));
        }
        */
        
        for(int i=0; i<strs.size(); i++){
            string tmp=strs[i];
            sort(tmp.begin(), tmp.end());
            if(strMap.find(tmp)==strMap.end()) strMap[tmp].push_back(strs[i]);
            else strMap[tmp].push_back(strs[i]);
        }
        
        for(auto mp:strMap){
            result.push_back(mp.second);
        }
        
        return result;
    }
};