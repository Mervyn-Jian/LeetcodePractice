class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> result;
        set<int> taken;
        sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates, result, results, taken, 0);
        return results;
    }
    
    void backtrack(int s, int target, vector<int>& candidates, vector<int> &result, vector<vector<int>> &results, set<int> &taken, int recurLayer){
        
        if(target==0){
            results.push_back(result);
            return;
        }else if(target<0){
            return;
        }
        
        for(int i=s; i<candidates.size(); i++){
            if(candidates[i]>target) continue;
            if(taken.find(candidates[i])!=taken.end()) continue;
            if(i>s && candidates[i-1]==candidates[i]) continue;
            
            result.push_back(candidates[i]);
            backtrack(i+1, target-candidates[i], candidates, result, results, taken, recurLayer+1);
            result.pop_back();
            
            if(recurLayer==0) taken.insert(candidates[i]);
        }
    }
};