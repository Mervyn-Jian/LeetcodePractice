class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int carry = 0;
        int i = a.size()-1;
        int j = b.size()-1;
        
        while(i>=0 || j>=0){
            
            int ad = (i>=0)? a[i]-'0' : 0;
            int bd = (j>=0)? b[j]-'0' : 0;
            int sum = ad ^ bd ^ carry;
            
            carry = (ad & bd) | (ad & carry) | (bd & carry);
            ans += (sum+'0');
      
            if(i>=0) i--;
            if(j>=0) j--;
        }
        if( carry!=0 ) ans += (carry+'0');
        reverse(ans.begin(), ans.end());
        
        return (ans.size()>0)? ans : "0";
    }
};