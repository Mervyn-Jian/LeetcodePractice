class Solution {
public:
    
    int lens[1000][1000];
    
    string longestPalindrome(string s) {
        if(s.size()==0) return "";
        
        int start=0, maxlen=0;
        
        for(int i=0; i<1000; i++){
            for(int j=0; j<1000; j++){
                lens[i][j] = 0;
            }
        }
        
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<s.size(); j++){
                if(i==j){
                    int len = 1;
                    lens[i][j] = len;
                    if(len>maxlen){
                        maxlen = len;
                        start = i;
                    }
                }
            }
        }
        
        for(int i=0; i<s.size(); i++){
            if(s[i]==s[i+1]){
                int len = 2;
                lens[i][i+1] = len;
                if(len>maxlen){
                    maxlen = len;
                    start = i;
                }
            }
        }
        
        for(int i=s.size()-1; i>=0; i--){
            for(int j=i+2; j<s.size(); j++){
                int len = 0;
                int tmpStart = i;
                if(s[i]==s[j] && (j-1)-(i+1)+1 == lens[i+1][j-1]){
                    len = lens[i+1][j-1] + 2;
                }else{
                    if(lens[i+1][j]>lens[i][j-1]){
                        len = lens[i+1][j];
                        tmpStart = i+1;
                    }else{
                        len = lens[i][j-1];
                    }
                }

                lens[i][j] = len;
                
                if(len>maxlen){
                    maxlen = len;
                    start = tmpStart;
                }
            }
        }
        
        return s.substr(start, maxlen);
    }
    
};