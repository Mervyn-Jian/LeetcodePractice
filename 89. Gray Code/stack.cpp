class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        set<int> exist;
        stack<int> curNumStack;
        
        result.push_back(0);
        exist.insert(0);
        curNumStack.push(0);
        
        while(!curNumStack.empty()){
            int curNum = curNumStack.top();
            curNumStack.pop();
            
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
                    curNumStack.push(curNum);
                    
                    break;
                }else{
                    continue;
                }
            }
        }
       
        return result;
    }

};