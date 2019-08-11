class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if(n<=0 || k<0) return result;
        
        vector<int> res;
        vector<int> nums = vector<int>(n);
        for(int i=1; i<=n; i++){
            nums[i-1] = i;
        }
        
        backtrack(0, k, nums, res, result);
        
        return result;
    }
    
    void backtrack(int s, int k, vector<int> &nums, vector<int>& res, vector<vector<int>> &result){
        if(res.size()==k){
            result.push_back(res);
            return;
        }
        
        for(int i=s; i<nums.size(); i++){
            res.push_back(nums[i]);
            backtrack(i+1, k, nums, res, result);
            res.pop_back();
        }
    }
};