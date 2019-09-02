class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memorize;
        vector<string> results;
        
        results = backtrack(s, wordSet, memorize);
        
        return results;
    }
    
    vector<string> backtrack(string s, unordered_set<string> &wordSet, unordered_map<string, vector<string>> &memorize){
        
        if(memorize.find(s) != memorize.end()) return memorize[s];
        if(s.size()==0) return {""};
        
        vector<string> result;
        for (string wordInSet : wordSet){
            string word = s.substr(0, wordInSet.size());
            
            if(word == wordInSet){ 
                vector<string> partResult;
                partResult = backtrack(s.substr(wordInSet.size()), wordSet, memorize);
                
                for(int i=0; i<partResult.size(); i++){
                    result.push_back( word + ((partResult[i].size()==0)? "":" ") + partResult[i] );
                }
            }
        }
        
        memorize[s] = result;
        return result;
    }
};