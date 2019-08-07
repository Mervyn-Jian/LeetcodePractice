class Solution {
public:
    int divide(int dividend, int divisor) {
        long ldivd = labs(dividend);
        long ldivs = labs(divisor);
        bool neg = (dividend>0) ^ (divisor>0);
        long quotient = 0;
        
        /* //iteration solution
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
        */
        
        //recursive solution
        quotient = div(ldivd, ldivs);
        
        quotient = neg? -quotient:quotient;
        quotient = max((long)-2147483648, quotient);
        quotient = min((long)2147483647, quotient);
        
        return (int)quotient;
    }
    
    long div(long ldivd, long ldivs){
        if(ldivd < ldivs) return 0;
        
        long ldivdSup = ldivs;
        long quotientSup = 1;
        long quotient;

        while((ldivdSup<<1) < ldivd){
            ldivdSup = ldivdSup<<1;
            quotientSup = quotientSup << 1;
        }

        quotient = quotientSup + div(ldivd-ldivdSup, ldivs);
        return quotient;
    }
};