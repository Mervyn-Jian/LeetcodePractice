class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        set<int> exist;
        int curNum;
        
        result.push_back(0);
        exist.insert(0);
        curNum = 0;
        
        backtrack(curNum, n, exist, result);
       
        return result;
    }
    
    void backtrack(int curNum, int n, set<int> &exist, vector<int> &result){
        for(int i=0; i<n; i++){
            int distinctBit = 1<<i;
            int nextNum;
            
            if( (curNum & distinctBit) == 0){
                nextNum = curNum | distinctBit;
            }else{
                nextNum = curNum & (~distinctBit);
            }
          
            if(exist.find(nextNum) == exist.end()){
                exist.insert(nextNum);
                result.push_back(nextNum);
                curNum = nextNum;
                backtrack(curNum, n, exist, result);
                break;
            }else{
                continue;
            }
        }
    }
};