class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maximum = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++){
              maximum = max(maximum,(nums[i]-1)*(nums[j]-1));
            }
        }
        return maximum;
    }
};
