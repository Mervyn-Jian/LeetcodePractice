class Solution {
public:
    int longestValidParentheses(string s) {
        
        if(s.size()<=0) return 0;
        vector<int> stack = {-1};
        int maxLen = 0;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(') stack.push_back(i);
            if(s[i]==')'){
                stack.pop_back();
                if(stack.size()!=0){
                    int len = i-stack.back();
                    if(len>maxLen) maxLen = len;
                }else{
                    stack.push_back(i);
                }
            }
        }
        
        return maxLen;
    }
};