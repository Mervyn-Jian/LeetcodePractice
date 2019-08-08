class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()<=0 || (matrix.size()>0 && matrix[0].size()<=0) ) return res;
        
        //create visited map 
        //if we encounter a visited element, turn right
        int m = matrix.size();
        int n = matrix[0].size();
        int total = m*n;
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));
        int dir = 0; //0: j++, 1: i++, 2: j--, 3: i--;
        
        int i=0;
        int j=0;
        int preI = -1;
        int preJ = -1;
        while(res.size()!=total){
            if(i>=0 && i<m && j>=0 && j<n){
                if(!visited[i][j]){
                    res.push_back(matrix[i][j]);
                    visited[i][j] = true;
                }else{
                    dir = (dir+1)%4;
                    i = preI;
                    j = preJ;
                }
            }else{
                dir = (dir+1)%4;
                i = preI;
                j = preJ;
            }
            
            preI = i;
            preJ = j;   
            switch(dir){
                case 0:
                    j++;
                    break;
                case 1:
                    i++;   
                    break;
                case 2:
                    j--;                 
                    break;
                case 3:
                    i--;
                    break;
            }
        }
        
        return res;
    }
};