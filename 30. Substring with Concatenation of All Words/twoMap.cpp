class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string, int> counts;
        map<string, int> seens;
        vector<int> results;
        int wLen=0;
        
        if(words.size()<=0 || s.size()<=0) return results;
        
        for(int i=0; i<words.size(); i++){
            counts[words[i]]++;
            if(i==0) wLen=words[i].size();
        }
        
        int i=0;
        int candidate=i;
        int seenWords=0;
        while( candidate<= (int)s.length()-wLen*(int)words.size() ){
            string w;
            
            w =s.substr(i, wLen);
            seens[w]++;

            if(seens[w]<=counts[w]){
                i+=wLen;
                seenWords++;
            }else{
                candidate++;
                i=candidate;
                seenWords=0;
                seens.clear();
            }

            if(seenWords==words.size()){
                results.push_back(candidate);

                candidate++;
                i=candidate;
                seenWords=0;
                seens.clear();
            }

        }
        
        return results;
    }
};