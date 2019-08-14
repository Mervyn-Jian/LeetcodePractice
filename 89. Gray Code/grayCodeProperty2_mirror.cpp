class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        
        // mirror last result and expand one bit at first bit.
        result.push_back(0);
        for(int i=0; i<n; i++){
            int lastResSize = result.size();
            
            vector<int> copyRes = vector<int>(result.begin(), result.end());
            for(int j=lastResSize-1; j>=0; j--){
                result.push_back(copyRes[j] | 1<<i);
            }
        }
        
        return result;
    }
};