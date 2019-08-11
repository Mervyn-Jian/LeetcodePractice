class Solution {
public:
    string minWindow(string s, string t) {
        //weird case, I think it should return "".
        if(t.size()==0 && s.size()>0){
            string str ="";
            str += s[0];
            return str;
        }
        
        map<char, int> sCount;
        map<char, int> tCount;
        int distinctCharNum;
        int curDistinctCharNum = 0;
        int left = 0;
        int right = 0;
        int minLen = INT_MAX;
        int resLeft = left;
        int resRight = right;
        
        for(int i=0 ;i<t.size(); i++){
            tCount[t[i]]++;
        }
        distinctCharNum = tCount.size();
        
        
        while(right < s.size()){
            char rightCh = s[right];
            sCount[rightCh]++;
            
            if(tCount.find(rightCh) != tCount.end() && tCount[rightCh] == sCount[rightCh]){
                curDistinctCharNum++;
            }
            //valid window
            if(curDistinctCharNum == distinctCharNum){
                if(right-left+1 < minLen){
                    minLen = right-left+1;
                    resLeft = left;
                    resRight = right;
                }
                
                //shrink valid window to find minimam window
                while(left<=right){
                    char leftCh = s[left];
                    sCount[leftCh]--;
                    left++;
                    
                    //if it not valid. we expand right to search new valid window.
                    if(tCount.find(leftCh) != tCount.end() && tCount[leftCh] > sCount[leftCh]){
                        curDistinctCharNum--;
                        break;
                    }
                    
                    if(curDistinctCharNum == distinctCharNum){
                        if(right-left+1 < minLen){
                            minLen = right-left+1;
                            resLeft = left;
                            resRight = right;
                        }
                    }
                    
                }
            }
            
            right++;
        }
        
        return (minLen==INT_MAX)? "" : s.substr(resLeft, minLen);
    }
    
};