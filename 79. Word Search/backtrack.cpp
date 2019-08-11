class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()<=0) return false;
        
        int m = board.size();
        int n;
        if(m<=0) return false;
        
        n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(backtrack(i, j, board, 0, word)) return true;
            }
        }
        
        return false;
    }
    
    bool backtrack(int i, int j, vector<vector<char>>& board, int s, string word){
        if(s==word.size()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) return false;
        if(board[i][j] != word[s]) return false;
        else{
            board[i][j] = '.';
            bool re =  backtrack(i, j+1, board, s+1, word) ||
                       backtrack(i, j-1, board, s+1, word) ||
                       backtrack(i+1, j, board, s+1, word) ||
                       backtrack(i-1, j, board, s+1, word);
            board[i][j] = word[s];
            return re;
        }
    }
};