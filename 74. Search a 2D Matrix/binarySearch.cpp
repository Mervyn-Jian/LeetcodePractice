class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //find row and apply binary search
        int m = matrix.size();
        if(m<=0) return false;
        int n = matrix[0].size();
        if(n<=0) return false;
        
        int rowIndex = 0;
        for(int i=0; i<m; i++){
            if(matrix[i][n-1] >= target ){
                rowIndex = i;
                break;
            }
        }
        
        int left = 0;
        int right = n-1;
        vector<int> row = matrix[rowIndex]; 
        while(left <= right){
            int mid = left + (right-left)/2;
            if(row[mid] == target) return true;
            else if(row[mid] > target) right = mid-1;
            else if(row[mid] < target) left = mid+1;
        }
        return false;
    }
};