class Solution {
public:
    double myPow(double x, int n) {
        if(n==0 || x==1) return 1;
        if(x==-1){
            return n%2==0? 1:-1;
        }
        
        bool inv = (n>=0)? false: true;
        double re = x;
        int power=1;
        int remainPower=0;
        int sign = (x>=0)? 1:-1;
        int reSign = sign;
        
        if(n==INT_MIN){
            n = -(n+1);
            remainPower = 1;
        }else if(inv){
            n = -n;
        }
        
        //n-2*power>=0  -> n/2 - power>=0 prevented overflow.
        while(n/2-power >= 0){
            re*=re;
            power *= 2;
            reSign*= sign;
            
            if(isinf(re)) return inv? 0:numeric_limits<double>::infinity()*reSign;
        }
        
        remainPower += n-power;
        while(remainPower!=0){
            re*=x;
            reSign*= sign;
            remainPower--;
            
            if(isinf(re)) return inv? 0:numeric_limits<double>::infinity()*reSign;
        }
        
        if(inv && re== 0) return numeric_limits<double>::infinity();
        else if(inv) return 1/re;
        else return re;
    }
    
};