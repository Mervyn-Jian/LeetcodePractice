class Solution {
public:
    bool isNumber(string s) {
        bool baseSign = false;
        bool baseNum = false;
        bool baseFloat = false;
        bool withSub = false;
        bool subSign = false;
        bool subNum = false;
        bool subFloat = false;
        bool endSpace = false;
        
        int i=0;
        while(s[i]==' '){
            i++;
        }
        
        for(; i<s.size(); i++){
            if(endSpace && s[i]!=' ') return false;
            else if(endSpace && s[i]==' ') continue;
            
            if(s[i]!='.' && s[i]!='+' && s[i]!='-' && s[i]!='e'){      
                if((s[i]-'0')>=0 && (s[i]-'0')<=9){
                    if(!withSub){
                        if(!baseNum) baseNum = true;
                    }else{
                        if(!baseNum) return false;
                        else if(baseNum && !subNum) subNum = true;
                    }
                }else if((s[i]-'0')<0 || (s[i]-'0')>9){    
                    if(s[i] ==' '){
                        if(!endSpace) endSpace = true;
                        else continue;
                    }else{
                        return false;
                    }
                }
            }
            
            if(s[i]=='-' || s[i]=='+'){
                if(!withSub){
                    if(!baseSign && !baseNum && !baseFloat) baseSign = true;
                    else if(baseNum || baseSign || baseFloat) return false;
                }else{
                    if(!subSign && !subNum && !subFloat) subSign=true;
                    else if(subSign || subNum || subFloat) return false;
                }
            }
           
            if(s[i]=='.'){
                if(!withSub){
                    if(!baseFloat) baseFloat = true;
                    else return false;
                }else{
                    return false;
                }
            }
            
            if(s[i]=='e'){
                if(baseNum){
                    if(!withSub) withSub = true;
                    else return false;
                }else{
                    return false;
                }
            }
        }
        
        if(!withSub) return baseNum;
        else return subNum;
    }
};