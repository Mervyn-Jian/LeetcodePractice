class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        
        double halfPow = myPow(x, n/2);
        if(n>0){
            if(n%2==0) return halfPow*halfPow;
            else return x*halfPow*halfPow;
        }else{
            double invX = 1/x;
            
            if(n%2==0) return halfPow*halfPow;
            else return invX*halfPow*halfPow;
        }
    }
    
};