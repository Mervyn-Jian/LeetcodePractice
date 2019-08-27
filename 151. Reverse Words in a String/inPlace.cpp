class Solution {
public:
    string reverseWords(string s) {
        int fast = 0;
        int slow = 0;
        //strip spaces at head and tail.
        while(s[fast] == ' ') fast++;
        s = s.substr(fast);
        reverse(0, s.size()-1, s);
    
        fast = 0;
        while(s[fast] == ' ') fast++;
        s = s.substr(fast);
        
        fast = 0;
        while(slow < s.size()){
            int preSpace = 0;
            // filetr previous space of the word
            while(fast < s.size() && s[fast] == ' '){
                fast++;
                preSpace++;
            }
            while(fast < s.size() && s[fast] != ' ') fast++;
            
            reverse(slow, fast-1, s);  //including swap previous space to end;
            
            fast++;                    //preserve one space in-between.
            slow = fast - preSpace;
            fast = slow;
        }
      
        //strip spaces at tail
        fast = s.size()-1;
        while(s[fast] == ' ') fast--;
        s = s.substr(0, fast-0+1);

        return s;
    }

    void reverse(int start, int end, string & str){
        int mid;
        
        end = std::min(end, (int)str.size()-1);
        mid = start + (end-start)/2;
        for(int i=start; i<=mid; i++){
            swap(str[i], str[start+end-i]);
        }
    }
};