class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int xorall=0;
        for(int i=0;i<=size;i++)
        {
            xorall ^= i;
        }
        for(int i =0;i<size;i++)
        {
            xorall ^= nums[i];
        }
        return xorall;
    }
};