class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat = vector<vector<int>>(n, vector<int>(n, 0));
        vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(n, false));
        vector<vector<int>> dir = {
            {0, 1}, {1,0}, {0,-1}, {-1,0}
        };
        int d = 0;
        int num =1;
        int count = 0;
        int toal = n*n;
        int i=0, j=0;
        int preI=-1;
        int preJ=-1;
        while(count<n*n){
            if(i>=0 && i<n && j>=0 && j<n){
                if(!visited[i][j]){
                    visited[i][j] = true;
                    mat[i][j] = num;
                    num++;
                    count++;
                }else{
                    d = (d+1)%4;
                    i=preI;
                    j=preJ;
                }
            }else{
                d = (d+1)%4;
                i=preI;
                j=preJ;
            }
            
            preI = i;
            preJ = j;
            
            i += dir[d][0];
            j += dir[d][1];
        }
        
        return mat;
    }
};