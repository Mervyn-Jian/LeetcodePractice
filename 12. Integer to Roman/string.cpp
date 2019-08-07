#include<algorithm>

class Solution {
public:
    string intToRoman(int num) {
        string result ="";
        char symbol[4][2]={{'I', 'V'},
                           {'X', 'L'},
                           {'C', 'D'},
                           {'M', 'N'}};
        
        int digit = 0;
        while(num!=0){
            int _num = num%10;
            
            if(_num<4){
                for(int i=0; i<_num; i++){
                   result+=symbol[digit][0];
                }
            }else if(_num==4){
                result+=symbol[digit][1];
                result+=symbol[digit][0];
            }else if(_num>=5 && _num<9){
                for(int i=0; i<_num-5; i++){
                   result+=symbol[digit][0];
                }
                result+=symbol[digit][1];
            }else if(_num==9){
                result+=symbol[digit+1][0];
                result+=symbol[digit][0];
            }
            
            num/=10;
            digit++;
        }
        
        reverse(result.begin(), result.end());
            
        return result;
    }
};