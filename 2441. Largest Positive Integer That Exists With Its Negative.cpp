class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = nums.size() - 1;

        while (i < j) {
            int sum = nums[i] + nums[j];

            if (sum == 0)
                return nums[j];
            else if (sum < 0)
                i++;
            else
                j--;
        }

        return -1;
    }
};
