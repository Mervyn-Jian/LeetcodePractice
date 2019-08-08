class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        
        int i=1;
        int j=INT_MAX;
        
        while(i<j){
            int mid=i+(j-i)/2;
            if(mid==x/mid) return mid;
            
            if(mid>x/mid){
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        
        if(i<=x/i) return i;
        else{
            return i-1;
        }
    }
};