class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        //it >= num - t
        //it <= num + t
        set<long> bstree;
        set<long>::iterator it;
        for(int i=0; i<nums.size(); i++){
            long num = (long)nums[i];
            it = bstree.lower_bound((long)num-(long)t);
            if(it!=bstree.end() && *it <= num+(long)t) return true;

            bstree.insert(num);
            if(i>=k) bstree.erase((long)nums[i-k]);
        }
        
        return false;
    }
};