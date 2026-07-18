class Solution {
public:
    int findGCD(vector<int>& nums) {
       sort(nums.begin(),nums.end()); 
       int a = nums[0];
       int b = nums[nums.size()-1];
      while(b!=0)
      {
        int temp = b;
        b = a%b;
        a=temp;
      }
      return a;
    }
};
