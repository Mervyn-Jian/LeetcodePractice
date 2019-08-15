class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> block;
        vector<vector<string>> blocks;
        
        backtrack(s.size()-1, 0, s, block, blocks);
        
        for(int i=0; i<blocks.size(); i++){
            string str = "";
            for(int j=blocks[i].size()-1; j>=0; j--){
                str += blocks[i][j];
                str += '.';
            }
            
            result.push_back(str.substr(0, str.size()-1));
        }
        
        return result;
    }
    
    void backtrack(int start, int count, string s, vector<string> &block, vector<vector<string>>& blocks){
        if(count == 4 && start < 0){
            blocks.push_back(block);
            return;
        }else if(count >= 4){
            return;
        }
        
        for(int i=start; i>=0; i--){
            string digit = "";
            
            //choose one digit
            digit += s[i];
            block.push_back(digit);
            backtrack(start-1, count+1, s, block, blocks);
            block.pop_back();
            
            //choose two digits
            if(i-1 >=0 && s[i-1] != '0'){
                block.push_back(to_string(s[i-1]-'0') + digit);
                backtrack(start-2, count+1, s, block, blocks);
                block.pop_back();
            }
            
            //choose three digits
            if(i-2 >=0 && s[i-2] != '0'){
                string threeDigit = to_string(s[i-2]-'0') + to_string(s[i-1]-'0') + digit;
                if(stoi(threeDigit) <= 255){
                    block.push_back(threeDigit);
                    backtrack(start-3, count+1, s, block, blocks);
                    block.pop_back();
                }
            }
            
            //each block should be adjacent.
            break;
        }
    }
};