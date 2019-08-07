class Solution {
public:
    int myAtoi(string str) {
        // number character substracted by '0' is within 0 ~ 9
        
        bool getNum = false, oneCheck = false;
        bool neg = false;
        vector<int> nums;
        for(int i=0; i<str.size(); i++){
            char ch = str[i];
            int iden = ch-'0';
            
            if(!oneCheck){
                if(ch=='-'){
                    neg = true;
                    getNum = true;
                    oneCheck = true;
                    continue;
                }
                if(ch=='+'){
                    neg = false;
                    getNum = true;
                    oneCheck = true;
                    continue;
                }
                
                if(iden<=9 && iden>=0){
                    getNum = true;
                    oneCheck = true;
                }  
            }
            
            if(!getNum){
                if(ch==' ') continue;
                if(iden>9 || iden<0) return 0;
            }else{
                if(iden>9 || iden<0) break;
                if((iden<=9 && iden>=0)){
                    nums.push_back(iden);
                }
            }    
        }
            
        int n = nums.size();
        int result = 0;
        while(n!=0){
            int num = nums[nums.size()-n];
          
            if(!neg){
                if(result > INT_MAX/10) return INT_MAX;
                if(result == INT_MAX/10 && num>7) return INT_MAX;
            }else{
                if(-result < INT_MIN/10) return INT_MIN;
                if(-result == INT_MIN/10 && num>7) return INT_MIN;
            }
            
            result = result*10 + num;
            n--;
        }
        
        return (!neg)? result : -result;
    }
};