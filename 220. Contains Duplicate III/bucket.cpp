class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t<0) return false;
        
        long bucketCapacity = (long)t+1; //make one bucket can put ts number
        map<long, long> buckets;
        
        for(int i=0; i<nums.size(); i++){
            long num = (long)nums[i]-INT_MIN; //let key is positive, and remove the posibility 3/5=0 and -3/5=0
            long bucketKey = num/bucketCapacity;

            if(buckets.count(bucketKey)>0) return true;
            if(buckets.count(bucketKey-1)>0 && labs(buckets[bucketKey-1]-(num+INT_MIN))<=(long)t) return true;
            if(buckets.count(bucketKey+1)>0 && labs(buckets[bucketKey+1]-(num+INT_MIN))<=(long)t) return true;
            
            buckets[bucketKey] = num+INT_MIN;
            if(i>=k) buckets.erase(((long)nums[i-k]-INT_MIN)/bucketCapacity);
        }
        
        return false;
    }
};