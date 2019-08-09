class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int w=0;
        
        while(w<words.size()){
            int leftWidth = maxWidth;
            int preOccupiedWidth = maxWidth;
            int countIndex = w;
            string str = "";
            
            for(; countIndex<words.size(); countIndex++){
                int wordLen = (int)(words[countIndex].size());
                
                if(preOccupiedWidth - wordLen < 0){
                    countIndex--;
                    break;
                }
                leftWidth -= wordLen;
                
                //place a word and a space in advance.
                preOccupiedWidth = preOccupiedWidth - wordLen - 1;
            }
            //last word
            if(countIndex >= words.size()) countIndex--;
            
            for(int i=w ; i<=countIndex; i++){
                str += words[i];
                
                int meanSpace;
                int div = countIndex- i;
                if(countIndex==words.size()-1) meanSpace = 1;
                else{
                    if(div == 0) meanSpace = leftWidth;
                    else{
                        if(leftWidth%div == 0) meanSpace = leftWidth / div;
                        else meanSpace = leftWidth / div +1;
                    }
                }
                
                int space = (leftWidth > meanSpace)? meanSpace : leftWidth;
                for(int j=0; j<space; j++){
                    str += ' ';
                }
                leftWidth -= meanSpace;
            }
            
            //last line
            for(int i=0; i<leftWidth; i++){
                str += ' ';
            }
            result.push_back(str);
            
            w = countIndex + 1;
        }
        
        return result;
    }
};