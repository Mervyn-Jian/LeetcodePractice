class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> triangle(rowIndex+1, 0);
        
        triangle[0] = 1;
        for(int i=1; i<rowIndex+1; i++){
            for(int j=i; j>=1; j--){
                triangle[j] += triangle[j-1];
            }            
        }
        
        return triangle;
    }
};