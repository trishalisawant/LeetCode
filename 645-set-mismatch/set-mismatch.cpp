class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        vector<int> fre(n + 1, 0);

        for (int i = 0; i < n; i++) {
            fre[nums[i]]++;
        }

        int d = 0, f = 0;

        for (int i = 1; i <= n; i++) {
            if (fre[i] == 2)
                d = i;
            else if (fre[i] == 0)
                f = i;
        }

        return {d, f};
    }
};