class Solution {
public:
    string countAndSay(int n) {
        vector<string> results={
          "1", "11", "21", "1211", "111221"  
        };
        
        int j=4;
        int k=n;
        while(k-5>0){
            string pre=results[j];
            
            int count=1;
            string result="";
            for(int i=1; i<pre.size(); i++){
                if(pre[i-1]==pre[i]){
                    count++;
                }else{
                    result+= (to_string(count)+pre[i-1]);
                    count=1;
                }
            }
    
            results.push_back(result+to_string(count)+pre[pre.size()-1]);
            
            j++;
            k--;
        }
        
        return results[n-1];
    }
};