class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
      bool even = false;
      bool odd = false;
      for( int n : nums1)
      {
         if(n % 2 ==0)
          even = true;
        else
         odd  = true;
      }
      return true;
    }
};