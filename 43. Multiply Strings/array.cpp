class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ans = vector<int>(num1.size()+num2.size(),0);
    
        for(int i=num2.size()-1; i>=0; i--){
            int lowNum = num2[i]-'0';
            for(int j=num1.size()-1; j>=0; j--){
                int upNum = num1[j]-'0';
                int product = lowNum*upNum;
                
                ans[i+j+1] += product;
                for(int k=i+j+1; k>0; k--){
                    int num = ans[k];
                    if(num>9){
                        ans[k] = num%10;
                        ans[k-1] += num/10;
                    }else{
                        break;
                    }
                }
            }
        }
        
        string result="";
        int nonZeroStart=ans.size()-1;
        for(int i=0; i<ans.size(); i++){
            if(ans[i]!=0){
                nonZeroStart=i;
                break;
            }
        }
        for(int i=nonZeroStart; i<ans.size(); i++){
            result+= (ans[i]+'0');
        }
        
        return result;
    }
};