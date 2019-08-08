class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.size()<=0) return res;
        
        map<string, vector<string>> alphaCount;
        
        int count[26];
        for(int i=0; i<strs.size(); i++){
            
            //reset counter
            for(int j=0; j<26; j++){
                count[j] = 0;
            }
            
            for(int j=0; j<strs[i].length(); j++){
                count[strs[i][j]-'a']++;
            }
            
            //encode hash
            string hash;
            for(int j=0; j<26; j++){
                char ch = 'a'+j;
                hash += ch + to_string(count[j]);
            }
            
            if(alphaCount.count(hash)==0){
                alphaCount[hash] = vector<string>(0);
            }
            alphaCount[hash].push_back(strs[i]);
        }
        
        for(map<string, vector<string>>::iterator it=alphaCount.begin(); it!=alphaCount.end(); it++){
            res.push_back(it->second);
        }
        
        return res;
    }
};