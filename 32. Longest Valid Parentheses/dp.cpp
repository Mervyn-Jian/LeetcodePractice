class Solution {
public:
    int longestValidParentheses(string s) {
        int n = (int)s.size();
        int maxLen = 0;
        vector<int> rightSideValidLen = vector<int>(n, 0);
        
        for(int i=1; i<n; i++){
            if(s[i]==')'){
                if(s[i-1]=='('){
                    if(i-2>=0) rightSideValidLen[i] = 2+rightSideValidLen[i-2];
                    else rightSideValidLen[i] = 2;
                }else if(s[i-1]==')'){
                    if(rightSideValidLen[i-1]>0){
                        if(i-rightSideValidLen[i-1]-1>=0){
                            if(s[i-rightSideValidLen[i-1]-1]=='('){
                                rightSideValidLen[i] = rightSideValidLen[i-1]+2;
                                if(i-rightSideValidLen[i-1]-2>=0 && rightSideValidLen[i-rightSideValidLen[i-1]-2]>0){
                                    rightSideValidLen[i] += rightSideValidLen[i-rightSideValidLen[i-1]-2];
                                }
                            }
                        }else rightSideValidLen[i] = 0;
                    }
                }
                if(rightSideValidLen[i] > maxLen) maxLen = rightSideValidLen[i];
            }
        }
        
        return maxLen;
    }
};