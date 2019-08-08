class Solution {
public:
    int mySqrt(int x) {
        long min_dist = INT_MAX;
        int res = 0;
        for(int i=0; i<=x; i++){
            long dist = (long)x-(long)i*(long)i;
            
            if(dist<0) break;
            
            if(dist<=min_dist){
                min_dist = dist;
                res = i;
            }
        }
        
        return res;
    }
};