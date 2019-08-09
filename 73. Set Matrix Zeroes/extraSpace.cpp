class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> zeroLocs;
        int m = matrix.size();
        if(m<=0) return;
        int n = matrix[0].size();
        if(n<=0) return;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0) zeroLocs.push_back({i, j});
            }
        }
        
        for(int i=0; i<zeroLocs.size(); i++){
            vector<int> loc = zeroLocs[i];
            
            for(int j=0; j<n; j++){
                matrix[loc[0]][j] = 0;
            }
            for(int j=0; j<m; j++){
                matrix[j][loc[1]] = 0;
            }
        }
    }
};