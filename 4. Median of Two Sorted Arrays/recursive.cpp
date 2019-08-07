class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int totalNum = n1 + n2;
        if(totalNum%2 == 0){
            return (findNthNum(nums1, 0, nums2, 0, totalNum/2)+findNthNum(nums1, 0, nums2, 0, totalNum/2+1)) /2;
        }else{
            return findNthNum(nums1, 0, nums2, 0, totalNum/2+1);
        }
    }
    
    double findNthNum(vector<int>& nums1, int i, vector<int>& nums2, int j, int n){
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if(n1-i>n2-j) return findNthNum(nums2, j, nums1, i, n);
        if(n1-i<=0) return nums2[j+n-1];
        if(n==1) return min(nums1[i], nums2[j]);
        
        //binary search
        int num1 = min(n1-i, n/2);
        int num2 = n - num1;
        
        if(nums1[i+num1-1] <= nums2[j+num2-1]){
            return findNthNum(nums1, i+num1, nums2, j, n-num1);
        }else{
            return findNthNum(nums1, i, nums2, j+num2, n-num2);
        }
    }
};