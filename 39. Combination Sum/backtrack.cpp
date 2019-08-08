class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> result;
        sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates, result, results);
        return results;
    }
    
    void backtrack(int s, int target, vector<int>& candidates, vector<int> &result, vector<vector<int>> &results){
        
        if(target==0){
            results.push_back(result);
            return;
        }else if(target<0){
            return;
        }
        
        for(int i=s; i<candidates.size(); i++){
            result.push_back(candidates[i]);
            backtrack(i, target-candidates[i], candidates, result, results);
            result.pop_back();
        }
    }
};