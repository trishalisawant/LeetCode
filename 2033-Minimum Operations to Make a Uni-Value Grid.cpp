class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                nums.push_back(grid[i][j]);
            }
        }
        int rem = nums[0] % x;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % x != rem) {
                return -1;
            }
        }
        sort(nums.begin(), nums.end());

        int median = nums[nums.size() / 2];
        int operations = 0;
        for (int i = 0; i < nums.size(); i++) {
            operations += abs(nums[i] - median) / x;
        }

        return operations;
    }
};
