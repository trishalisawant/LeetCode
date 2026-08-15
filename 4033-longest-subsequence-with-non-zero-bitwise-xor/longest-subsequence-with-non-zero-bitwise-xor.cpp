class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;
        bool x = false;
        for(int n : nums){
          xr ^=n;
           if(n!=0) x=true;
        }
        if(xr != 0) return nums.size();
        if(x) return nums.size()-1;
         return 0;
    }
};