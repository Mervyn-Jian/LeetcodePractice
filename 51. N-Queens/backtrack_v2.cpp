class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> res;
        vector<vector<string>> results;
        set<vector<string>> resSet;
        
        //initalize the chess
        for(int i=0; i<n; i++){
            string s="";
            for(int j=0; j<n; j++){
                s+='.';
            }
            res.push_back(s);
        }
        
        //backtrack: place the queen.
        backtrack(0, 0, res, results, resSet);
        
        return results;
    }
    
    void backtrack(int i, int q, vector<string> &res, vector<vector<string>> &results, set<vector<string>> &resSet){
        if(q==res.size()){
            results.push_back(res);
            return;
        }
        
        for(int j=0; j<res.size(); j++){
            if(res[i][j]=='.'){  
                if(valid(i, j, res)){   
                    res[i][j]='Q';
                    q++;

                    backtrack(i+1, q, res, results, resSet);
                    res[i][j]='.';
                    q--;
                }
            }
        }
    }
    
    bool valid(int m, int n, vector<string> &res){
       
        for(int i=0; i<res.size(); i++){
            if(res[m][i]=='Q' && i!=n) return false;
            if(res[i][n]=='Q' && i!=m) return false;
        }
        
        int i=m; 
        int j=n;
        int x=m;
        int y=n;
        while(i>=0){
            if(j>=0 && res[i][j]=='Q' && i!=m && j!=n) return false;
            if(y<res.size() && res[x][y]=='Q' && x!=m && y!=n) return false;
            i--;
            j--;
            x--;
            y++;
        }
        
        i=m; 
        j=n;
        x=m;
        y=n;
        while(i<res.size()){
            if(j<res.size() && res[i][j]=='Q' && i!=m && j!=n) return false;
            if(y>=0 && res[x][y]=='Q' && x!=m && y!=n) return false;
            i++;
            j++;
            x++;
            y--;
        }
        
        return true;
    }
};