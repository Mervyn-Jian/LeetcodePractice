class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0;
        int n1=nums1.size();
        int n2=nums2.size();
        
        vector<double> mergeNums;
        
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                mergeNums.push_back(nums1[i]);
                i++;
            }else{
                mergeNums.push_back(nums2[j]);
                j++;
            }
        }

        if(i<n1){
            for(;i<n1;i++){
                mergeNums.push_back(nums1[i]);
            }
        }
        if(j<n2){
            for(;j<n2;j++){
                mergeNums.push_back(nums2[j]);
            }
        }
        
        if(mergeNums.size()%2==1){
            return mergeNums[mergeNums.size()/2];
        }else{
            return (mergeNums[mergeNums.size()/2] + mergeNums[mergeNums.size()/2-1])/2;
        }
    }
};