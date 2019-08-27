class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row <= 0) return;
        int col = board[0].size();
        
        //find connected components from boundary nodes.
        //bfs and use original memory to be visited records.
        queue<int> que;
        for(int j=0; j<col; j++){
            if(board[0][j]=='O'){
                que.push(0*col+j);
                board[0][j] = 'v';
            }
            if(board[row-1][j]=='O'){
                que.push((row-1)*col+j);
                board[row-1][j] = 'v';
            }
        }
        for(int i=0; i<row; i++){
            if(board[i][0]=='O'){
                que.push(i*col+0);
                board[i][0] = 'v';
            }
            if(board[i][col-1]=='O'){
                que.push(i*col+col-1);
                board[i][col-1] = 'v';
            }
        }
        
        while(!que.empty()){
            int node = que.front();
            que.pop();
            int i = node / col;
            int j = node % col;
            
            if(i-1>=0 && board[i-1][j]=='O'){
                que.push((i-1)*col+j);
                board[i-1][j] = 'v';
            } 
            if(i+1<row && board[i+1][j]=='O'){
                que.push((i+1)*col+j);
                board[i+1][j] = 'v';
            }
            if(j-1>=0 && board[i][j-1]=='O'){
                que.push(i*col+j-1);
                board[i][j-1] = 'v';
            }
            if(j+1<col && board[i][j+1]=='O'){
                que.push(i*col+j+1);
                board[i][j+1] = 'v';
            }
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j]=='O') board[i][j] = 'X';
                if(board[i][j]=='v') board[i][j] = 'O';
            }
        }
    }
};