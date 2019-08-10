class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m<=0) return;
        int n = matrix[0].size();
        if(n<=0) return;
        
        bool firstRowZero = false;
        bool firstColZero = false;
        for(int i=0; i<m; i++){
            if(matrix[i][0] == 0) firstRowZero = true;
        }
        for(int j=0; j<n; j++){
            if(matrix[0][j] == 0) firstColZero = true;
        }
        
        //use first row and first column to record zeros
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j]==0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        //set first row and column
        if(firstRowZero){
            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
        
        if(firstColZero){
            for(int j=0; j<n; j++){
                matrix[0][j] = 0;
            }
        }
    }
};