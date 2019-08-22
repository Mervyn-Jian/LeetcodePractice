class Solution {
public:
    string reverseStr(string s, int k) {
        reverse(0, s, k);
        return s;
    }
    
    void reverse(int start, string &s, int k){
        int end = min(start+k-1, (int)s.size()-1);
        if(start > end) return;
     
        int mid = start + (end-start)/2;
        for(int i=start; i<=mid; i++){
            swap(s[i], s[start + (end-i)]);
        }
        reverse(start+2*k, s, k);
    }
};