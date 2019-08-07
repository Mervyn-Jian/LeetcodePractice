class Solution {
public:
    int strStr(string haystack, string needle) {
        //implement kmp algorithm
        if(needle.length()<=0) return 0;
        
        vector<int> kmp = lenTableOfSamePrefixSuffix(needle);
        int i=0;
        int j=0;
        
        while(i<haystack.length()){
            if(haystack[i]==needle[j]){
                if(j==needle.length()-1) return i-j;
                i++;
                j++;
            }else{
                if(j>0){
                    j = kmp[j-1];
                }else{
                    i++;
                }
            }
        }
        return -1;
    }
    
    vector<int> lenTableOfSamePrefixSuffix(string needle){
        vector<int> table = vector<int>(needle.length(), 0);
        int j=0;
        int i=1;
        
        while(j<needle.size() && i<needle.size()){
            if(needle[i]==needle[j]){
                table[i] = j+1;
                i++;
                j++;
            }else{
                if(j>0){
                    j = table[j-1];
                }else{
                    table[i] = 0;
                    i++;
                }
            }
        }
        return table;
    }
};