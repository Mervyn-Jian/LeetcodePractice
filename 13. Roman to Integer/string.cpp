class Solution {
public:
    int romanToInt(string s) {
        map<char, int> nums;
        nums.insert(pair<char, int>('I', 1));
        nums.insert(pair<char, int>('V', 5));
        nums.insert(pair<char, int>('X', 10));
        nums.insert(pair<char, int>('L', 50));
        nums.insert(pair<char, int>('C', 100));
        nums.insert(pair<char, int>('D', 500));
        nums.insert(pair<char, int>('M', 1000));
        
        int pre=0;
        int cur=0;
        int sum=0;
        for(int i=s.length()-1; i>=0; i--){
            cur = nums[s[i]];
            if(cur>=pre){
                sum+=cur;
            }else{
                sum-=cur;
            }
            pre = cur;
        }
        
        return sum;
    }
};