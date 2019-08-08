class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> res;
        vector<vector<int>> result;
        
        result.push_back(res);
        backtrack(0, res, nums, result);
        return result;
    }
    
    void backtrack(int s, vector<int> &res, vector<int>& nums, vector<vector<int>> &result){
        if(s==nums.size()) return;
        for(int i=s; i<nums.size(); i++){
            res.push_back(nums[i]);
            result.push_back(res);
            backtrack(i+1, res, nums, result);
            res.pop_back();
        }
    }
};