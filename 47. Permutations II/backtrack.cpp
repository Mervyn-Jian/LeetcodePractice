class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> re;
        vector<bool> take=vector<bool>(nums.size(), false);
        vector<int> numsCopy = vector<int>(nums.begin(), nums.end());
        
        sort(numsCopy.begin(), numsCopy.end());
        backtrack(numsCopy, re, result, take);
        
        return result;
    }
    
    void backtrack(vector<int>& nums, vector<int> &re, vector<vector<int>> &result, vector<bool> &take){
        if(nums.size()==re.size()){
            result.push_back(re);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(take[i]) continue;
            if(i-1>=0 && nums[i]==nums[i-1] && take[i-1]) continue;
            re.push_back(nums[i]);
            take[i]=true;
            backtrack(nums, re, result, take);
            re.pop_back();
            take[i]=false;
        }
    }
};