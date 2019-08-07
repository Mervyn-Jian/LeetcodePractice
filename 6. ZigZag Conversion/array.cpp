class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        
        vector<vector<char>> zigzag = vector<vector<char>>(numRows);
        string result = "";
        
        int curRow = 0;
        bool forward = true;
        for(int i=0; i<s.size(); i++){
            zigzag[curRow].push_back(s[i]);
            
            if(curRow == numRows-1) forward = false;
            if(curRow == 0) forward = true;
            
            if(forward) curRow++;
            else curRow--;   
        }
        
        for(int i=0; i<zigzag.size(); i++){
            for(int j=0; j<zigzag[i].size(); j++){
                result+=zigzag[i][j];
            }
        }
        
        return result;
    }
};