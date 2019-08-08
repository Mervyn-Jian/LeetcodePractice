class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        set<int> taken;
        vector<vector<int>> result;
        vector<int> res = vector<int>();
        backtrack(nums, res, result, taken);
        
        return result;
    }
    
    void backtrack(vector<int>& nums, vector<int>& res, vector<vector<int>> &result, set<int> &taken){
        if(res.size()==nums.size()){
            result.push_back(res);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(taken.find(nums[i])==taken.end()){
                taken.insert(nums[i]);
                res.push_back(nums[i]);
                backtrack(nums, res, result, taken);
                res.pop_back();
                taken.erase(nums[i]);
            }
        }
    }
};