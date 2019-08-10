class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> zeroRows;
        set<int> zeroCols;
        int m = matrix.size();
        if(m<=0) return;
        int n = matrix[0].size();
        if(n<=0) return;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }
        
        for(auto row : zeroRows){
            for(int j=0; j<n; j++){
                matrix[row][j] = 0;
            }
        }
        
        for(auto col : zeroCols){
            for(int j=0; j<m; j++){
                matrix[j][col] = 0;
            }
        }
        
    }
};