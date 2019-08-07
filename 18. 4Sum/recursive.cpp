class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size()<=0) return result;
        
        vector<int> res;
        sort(nums.begin(),nums.end());
        
        ksum(4, 0, target, nums, res, result);
        
        return result;
    }
    
    void ksum(int k, int s, int t, vector<int> &nums, vector<int> &res, vector<vector<int>> &result){
        if(s>=nums.size()-1) return;
        if(k==2){
            if(nums.size()-s <2) return;
            int l=s;
            int r = nums.size()-1;
            while(l<r){
                int nl =nums[l];
                int nr =nums[r];
                int sum =nl+nr;
                if(sum==t){
                    res.push_back(nl);
                    res.push_back(nr);
                    result.push_back(res);
                    res.pop_back();
                    res.pop_back();
                    
                    while(l+1<nums.size() && nums[l]== nums[l+1]) l++;
                    while(r-1>s && nums[r]== nums[r-1]) r--;
                    l++;
                    r--;
                }else if(sum<t){
                    l++;
                }else if(sum>t){
                    r--;
                }
            }
        }else{ 
            for(int i=s; i<nums.size();i++){
                if(i>s && nums[i-1]==nums[i]) continue;
                res.push_back(nums[i]);
                ksum(k-1, i+1, t-nums[i], nums, res, result);
                res.pop_back();
            }
        }
    }
};