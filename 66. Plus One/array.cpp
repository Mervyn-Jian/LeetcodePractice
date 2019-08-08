class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int carry = 0;
        for(int i=digits.size()-1; i>=0; i--){
            int num = (i==digits.size()-1)? digits[i]+1+carry : digits[i]+carry;
            carry = num / 10;
            res.push_back(num % 10);
        }
        if(carry != 0) res.push_back(carry);
        reverse(res.begin(), res.end());
        
        if(digits.size()<=0) res.push_back(1);
        return res;
    }
};