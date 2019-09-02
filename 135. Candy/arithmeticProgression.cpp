class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() <= 0) return 0;
        
        int candy = 0;
        int give = 1;
        int waitChildren = 0;
        int accumulatedGive = 0;
        
        candy += give;
        for(int i=1; i<ratings.size(); i++){
            if(ratings[i] >= ratings[i-1]){
                
                // handle children who wait in the previous queue 
                if(waitChildren > 0){
                    // calculate arithmetic progression
                    int accumulatedGive = (waitChildren * (waitChildren+1))/2;
                    candy += accumulatedGive;
                    
                    if(waitChildren >= give){
                        candy += (waitChildren-give) + 1;
                    }
                    
                    waitChildren = 0;
                    give = 1;
                }
                
                if(ratings[i] == ratings[i-1]){
                    give = 1;
                }else{
                    give++;
                }
                
                candy += give;
            }else{
                // add a child to the previous queue.
                waitChildren++;
            }
        }
        
        // handle children who wait in the previous queue 
        if(waitChildren > 0){
            // calculate arithmetic progression
            int accumulatedGive = (waitChildren * (waitChildren+1))/2;
            candy += accumulatedGive;

            if(waitChildren >= give){
                candy += (waitChildren-give) + 1;
            }
        }           
        
        return candy;
    }
};