class Solution {
public:
    
    vector<string> letterCombinations(string digits) {
        map<char, string> letters;
        vector<string> results;
        
        if(digits.size()==0) return results;
        
        results.push_back("");
        
        letters={
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        
        for(int i=0; i<digits.length(); i++){          
            vector<string> tmpResults;
            string alphas = letters[digits[i]];
            for(int j=0; j<alphas.length(); j++){
                for(int k=0; k<results.size(); k++){
                    tmpResults.push_back(results[k]+alphas[j]);
                }
            }
            
            results = tmpResults;
        }

        
        return results;
    }
    
};