class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> tmpResult;
        vector<vector<string>> results;
        
        backtrack(0, s, tmpResult, results);
        
        return results;
    }
    
    void backtrack(int start, string &s, vector<string> &tmpResult, vector<vector<string>> &results){
        if(start >= s.size()){
            results.push_back(tmpResult);
        }
        
        for(int i=start; i<s.size(); i++){
            string subStr = s.substr(start, i-start+1);
            if(subStr.size() > 0 && isPalindrome(subStr)){
                tmpResult.push_back(subStr);
                backtrack(i+1, s, tmpResult, results);
                tmpResult.pop_back();
            }
        }
    }
    
    bool isPalindrome(string &str){
        for(int i=0; i<str.size()/2; i++){
            if(str[i] != str[str.size()-i-1]) return false;
        }
        return true;
    }
};