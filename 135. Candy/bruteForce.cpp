class Solution {
public:
    int candy(vector<int>& ratings) {
        int candy = 0;
        int candiCandy = 1;
        
        vector<int> given = vector<int>(ratings.size(), 1);
        for(int i=0; i<ratings.size(); i++){
            if(i-1>=0){
                if(ratings[i-1] < ratings[i]){
                    candiCandy++;
                }else if(ratings[i-1] > ratings[i] && candiCandy == 1){
                    int formerChild = i-1;
                    while(formerChild>=0){
                        if(ratings[formerChild] > ratings[formerChild+1] && given[formerChild] <= given[formerChild+1]){
                            // give more candy to previous child
                            candy += 1; 
                            given[formerChild]++;
                        }else{
                            break;
                        }
                        formerChild--;
                    }
                }else if(candiCandy > 1){
                    candiCandy = 1;    // minimize the given candy.
                }
                
            }else if(i+1 < ratings.size()){
                if(ratings[i+1] < ratings[i]){
                    candiCandy++;
                }
            }
            
            given[i] = candiCandy; 
            candy += candiCandy;
        }
        
        return candy;
    }
};