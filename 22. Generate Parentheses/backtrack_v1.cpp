class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string res = "";
        vector<string> result;
        map<char, int> letters = {
            {'(', n},
            {')', n}
        };
        
        backtrack(0, n, letters, res, result);
        
        return result;
    }
    
    void backtrack(int cur, int n, map<char, int> &letters, string &res, vector<string> &result){
        if(cur==2*n){
            if(isValid(res)) result.push_back(res);
            return;
        }
        
        for(map<char,int>::iterator it=letters.begin(); it!=letters.end(); it++){
            if(it->second<=0) continue;
            res+= (it->first);
            it->second--;
                
            backtrack(cur+1, n, letters, res, result);                   
            res = res.substr(0, res.size()-1);
            it->second++;
        }
    }

    bool isValid(string s){
        vector<char> stack;
        
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            if(ch=='(') stack.push_back(ch);
            else if(ch==')'){
                char top;

                if(stack.size()>0) top=stack.back();
                else return false;
                
                if(top=='('){
                    stack.pop_back();
                }else{
                    return false;
                }
            }
        }
        
        return stack.size()==0? true: false;
    }
};