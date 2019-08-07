class Solution {
public:
    int divide(int dividend, int divisor) {
        long ldivd = labs(dividend);
        long ldivs = labs(divisor);
        bool neg = (dividend>0) ^ (divisor>0);
        long quotient = 0;
        
        while(ldivd>=ldivs){
            long ldivdSup = ldivs;
            long quotientSup = 1;
            
            while((ldivdSup<<1) < ldivd){
                ldivdSup = ldivdSup<<1;
                quotientSup = quotientSup << 1;
            }
            
            ldivd -= ldivdSup;
            quotient += quotientSup;
        }
        
        quotient = neg? -quotient:quotient;
        quotient = max((long)-2147483648, quotient);
        quotient = min((long)2147483647, quotient);
        
        return (int)quotient;
    }
};