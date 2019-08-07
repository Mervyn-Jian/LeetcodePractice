#include <math.h>

class Solution {
public:
    int reverse(int x) {
        cout<<INT_MAX<<endl<<INT_MIN<<endl;
        
        if(x==INT_MIN) return 0;
        
        bool neg = x<0? true: false;
        if(neg) x = -x;
        
        vector<int> nums;
        int digits = 0;
        
        while(x!=0){
            nums.push_back(x%10);
            x/=10;
            digits++;
        }
        
        int result = 0;
        int i=0;
        while(digits!=0){
            result *= 10;
            result += nums[i];
            
            digits--;
            i++;
            
            if(i==9 && digits!=0){
                if(result > INT_MAX/10)  return 0;
                if(result == INT_MAX/10 && nums[i]>7 && !neg)  return 0;
                if(result == INT_MAX/10 && nums[i]>8 && neg)  return 0;
            }
        }
        
        return (!neg)? result:-result;
    }
};