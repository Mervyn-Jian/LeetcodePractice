class Solution {
public:
    bool** table;
    
    bool isMatch(string s, string p) {
        
        table = new bool*[s.length()+1];
        for(int i=0; i<s.length()+1; i++){
            table[i] = new bool[p.length()+1];
        }
        
        //initialize table
        for(int i=0; i<s.length()+1; i++){
            for(int j=0; j<p.length()+1; j++){
                table[i][j] = false;
            }
        }
        
        //empty string and pattern comparison
        table[s.length()][p.length()] = true;
        
        //empty string comparison    
        for(int j=p.length()-1; j>=0; j--){
            if(j+1<p.length() && p[j+1]=='*'){
                table[s.length()][j] = table[s.length()][j+2];
            }
        }
        
        for(int i=s.length()-1; i>=0; i--){
            for(int j=p.length()-1; j>=0; j--){
                bool ans = false;
                bool firstMatch = false;
                
                if(i<s.length() &&  (s[i]==p[j] || p[j]=='.') ){
                    firstMatch = true;
                }
                
                if(j+1<p.length() && p[j+1] =='*'){
                    ans = (table[i+1][j] && firstMatch) || table[i][j+2] ;
                }else{
                    ans = table[i+1][j+1] && firstMatch;
                }
                
                table[i][j] = ans;
            }
        }
        
        return table[0][0];
    }
};