#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if((x!=0 && x%10==0)) return false;
        
        int invertHalf = 0;
        while(x>invertHalf){
            invertHalf = invertHalf*10 + x%10;
            x/=10;
        }
        
        //even digits and odd digits
        return (x==invertHalf) || (x==invertHalf/10);
    }
};