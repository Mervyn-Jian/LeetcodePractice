class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> rowHash, colHash, gridHash;
        
        int n = board.size();
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]!='.'){
                    char num = board[i][j];
                    string rowh = to_string(i)+num;
                    string colh = to_string(j)+num;
                    string gridh = to_string(i/3)+to_string(j/3)+num;
                    
                    if(rowHash.find(rowh) != rowHash.end()) return false;
                    else rowHash.insert(rowh);
                    
                    if(colHash.find(colh) != colHash.end()) return false;
                    else colHash.insert(colh);
                    
                    if(gridHash.find(gridh) != gridHash.end()) return false;
                    else gridHash.insert(gridh);
                }
            }
        }
        
        return true;
    }
};