class Solution {
public:
    bool isValid(string s) {
        
        vector<int> stack;
        if(s.size()==0) return true;
        else stack.push_back(s[0]);
        
        for(int i=1; i<s.length(); i++){
            char ch = s[i];
            if(ch=='(' || ch=='{' || ch=='['){
                stack.push_back(ch);
            }
            
            char stackCh;
            if(stack.size()!=0) stackCh= stack.back();
            switch(ch){
                case ')':
                    if(stackCh == '('){
                        stack.pop_back();
                    }else{
                        return false;
                    }
                    break;
                    
                case '}':
                    if(stackCh == '{'){
                        stack.pop_back();
                    }else{
                        return false;
                    }
                    break;
                    
                case ']':
                    if(stackCh == '['){
                        stack.pop_back();
                    }else{
                        return false;
                    }
                    break;
            }
        }
        
        return stack.size()==0? true:false;
    }
};