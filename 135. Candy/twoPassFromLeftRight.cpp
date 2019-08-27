class Solution {
public:
    int candy(vector<int>& ratings) {
        int candy = 0;
        
        vector<int> given = vector<int>(ratings.size(), 1);
        //from left
        for(int i=1; i<given.size(); i++){
            if(ratings[i-1] < ratings[i]) given[i] = given[i-1] + 1;
        }
        
        //from right
        for(int i=given.size()-2; i>=0; i--){
            if(ratings[i+1] < ratings[i]){
                given[i] = max(given[i], given[i+1] + 1);
            }
        }
        
        for(int i=0; i<given.size(); i++){
            candy += given[i];
        }
        
        return candy;
    }
};