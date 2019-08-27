class Solution {
public:
    
    class UnionFind{
    public:
        UnionFind(int n){
            componentNum = n;
            componentIds = new int[n];
            treeHeights = new int[n];
            
            for(int i=0; i<n; i++){
                componentIds[i] = i;
                treeHeights[i] = 0;
            }
        }
        
        int whichComponent(int i){
            while(componentIds[i] != i){
                componentIds[i] = componentIds[componentIds[i]]; //balance tree height
                i = componentIds[i];
            }
            
            return componentIds[i];
        }
        
        void unionComponent(int i, int j){
            int componentI = whichComponent(i);
            int componentJ = whichComponent(j);
            if(componentI != componentJ){
                int heightI = treeHeights[componentI];
                int heightJ = treeHeights[componentJ];
                
                if(heightI > heightJ) componentIds[componentJ] = componentI;
                else if(heightJ > heightI) componentIds[componentI] = componentJ;
                else{
                    componentIds[componentJ] = componentI;
                    treeHeights[componentI]++;
                }
                componentNum--;
            }
        }
        
        bool isConnected(int i, int j){
            return whichComponent(i) == whichComponent(j);
        }
        
        ~UnionFind(){
            delete [] componentIds;
            delete [] treeHeights;
        }
    private:
        int n;
        int* componentIds;
        int* treeHeights;
        int componentNum;
    };
    
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row <= 0) return;
        int col = board[0].size();
        
        UnionFind unionFind(row*col + 1); //+1 is component out of the board.
        
        for(int j=0; j<col; j++){
            if(board[0][j]=='O'){
                unionFind.unionComponent(0*col+j, row*col);
            }
            if(board[row-1][j]=='O'){
                unionFind.unionComponent((row-1)*col+j, row*col);
            }
        }
        for(int i=0; i<row; i++){
            if(board[i][0]=='O'){
                unionFind.unionComponent(i*col+0, row*col);
            }
            if(board[i][col-1]=='O'){
                unionFind.unionComponent(i*col+col-1, row*col);
            }
        }
        
        for(int i=1; i<row-1; i++){
            for(int j=1; j<col-1; j++){
                if(board[i][j] != 'O') continue;
                int node = i*col + j;
                
                if(i-1>=0 && board[i-1][j]=='O'){
                    unionFind.unionComponent((i-1)*col+j, node);
                } 
                if(i+1<row && board[i+1][j]=='O'){
                    unionFind.unionComponent((i+1)*col+j, node);
                }
                if(j-1>=0 && board[i][j-1]=='O'){
                    unionFind.unionComponent(i*col+j-1, node);
                }
                if(j+1<col && board[i][j+1]=='O'){
                    unionFind.unionComponent(i*col+j+1, node);
                }
            }
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(!unionFind.isConnected(i*col+j, col*row)) board[i][j] = 'X';
            }
        }
    }
};