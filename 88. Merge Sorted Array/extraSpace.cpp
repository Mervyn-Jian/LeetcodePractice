class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> copyNums1 = vector<int>(nums1.begin(), nums1.begin()+m);
        int i = 0;
        int j = 0;
        int k = 0;
        while(i<m || j<n){
            if(i>=m){
                nums1[k] = nums2[j];
                j++;
                k++;
                continue;
            }
            
            if(j>=n){
                nums1[k] = copyNums1[i];
                i++;
                k++;
                continue;
            }
            
            int ni = copyNums1[i];
            int nj = nums2[j];
            if(ni < nj){
                nums1[k] = ni;
                i++;
                k++;
            }else{
                nums1[k] = nj;
                j++;
                k++;
            }
        }
    }
};