#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.size()<=1) return result;
        
        vector<pair<int, int>> tracked_sort_num;
        for(int i=0; i<nums.size(); i++){
            pair<int, int> numpair;
            numpair.first = nums[i];
            numpair.second = i;
            tracked_sort_num.push_back(numpair);
        }
        int left=0;
        int right = nums.size()-1;
        
        sort(tracked_sort_num.begin(), tracked_sort_num.end());
        
        int sum;
        while(left<right){
            sum = tracked_sort_num[left].first + tracked_sort_num[right].first;
            if(target>sum) left++;
            else if(target<sum) right--;
            else{
                result.push_back(tracked_sort_num[left].second);
                result.push_back(tracked_sort_num[right].second);
                
                return result;
            }
        }
        return result;
        
    }
};