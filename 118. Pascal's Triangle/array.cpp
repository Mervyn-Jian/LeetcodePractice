class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for(int i=0; i<numRows; i++){
            vector<int> row;
            if(i==0) row = {1};
            else if(i==1) row = {1,1};
            else{
                vector<int> upperRow = triangle.back();
                row.push_back(1);
                for(int i=0; i<upperRow.size()-1; i++){
                    row.push_back(upperRow[i]+upperRow[i+1]);
                }
                row.push_back(1);
            }
            triangle.push_back(row);
        }
        
        return triangle;
    }
};