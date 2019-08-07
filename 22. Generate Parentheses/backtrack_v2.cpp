class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string res = "";
        vector<string> result;
        
        backtrack(n, 0, res, result);
        
        return result;
    }
    
    void backtrack(int open, int close, string res, vector<string> &result){
        if(open==0 && close==0){
            result.push_back(res);
            return;
        }
        
        if(open>0) backtrack(open-1, close+1, res+"(", result);
        if(close>0) backtrack(open, close-1, res+")", result);
    }
};