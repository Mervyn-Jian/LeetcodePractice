class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
    
    bool backtrack(vector<vector<char>>& board){
    
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]=='.'){
                    for(int c=1; c<10; c++){
                        if(ruleCheck(board, i, j, c+'0')){
                            board[i][j] = (c+'0');
                            if(!backtrack(board)){
                                board[i][j] = '.';
                            }else{
                                return true;
                            }
                        }
                    }
                    return false;
                }
                
            }
        }
        
        return true;
    }
    
    bool ruleCheck(vector<vector<char>>& board, int row, int col, char num){
        for(int i=0; i<board.size(); i++){
            if(board[row][i] != '.' && board[row][i] == num) 
                return false;
            if(board[i][col] != '.' && board[i][col] == num) 
                return false;
            
            if(board[3*(row/3)+ i/3][3*(col/3)+ i%3] != '.' && board[3*(row/3)+ i/3][3*(col/3)+ i%3] == num) 
                return false;
        }  
        
        return true;
    }
    
};