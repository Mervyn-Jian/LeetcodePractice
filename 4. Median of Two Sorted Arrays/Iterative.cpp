class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalNum = nums1.size() + nums2.size();
        if(totalNum%2 == 0){
            return (findNthNum(nums1, nums2, totalNum/2)+findNthNum(nums1, nums2, totalNum/2-1)) /2;
        }else{
            return findNthNum(nums1, nums2, totalNum/2);
        }
    }
    
    double findNthNum(vector<int>& nums1, vector<int>& nums2, int n){
        int n1 = nums1.size()-1;
        int n2 = nums2.size()-1;
        
        if(n1<0) return nums2[n];
        if(n2<0) return nums1[n];
        
        if(nums1[n1]<=nums2[0]){
            if(n<= n1){
                return nums1[n];
            }else{
                return nums2[n-n1-1];
            }
        }
        if(nums2[n2]<=nums1[0]){
            if(n<= n2) return nums2[n];
            else return nums1[n-n2-1];
        }
   
        int in1 = 0;
        int in2 = 0;
        int cur = 0;
        while(n>=0){   
            
            if(in1>n1){
                cur = nums2[in2];
                in2++;
                n--;
                continue;
            }
            if(in2>n2){
                cur = nums1[in1];
                in1++;
                n--;
                continue;
            }
            
            if(nums1[in1]<=nums2[in2]){
                cur = nums1[in1];
                in1++;
            }else{
                cur = nums2[in2];
                in2++;
            }
            n--;
        }

        return cur;
    }
};