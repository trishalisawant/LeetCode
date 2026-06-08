class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
         sort(nums.begin(), nums.end(), greater<int>());

        int totalSum = 0;
        for (int x : nums) {
            totalSum += x;
        }

        vector<int> ans;
        int chosenSum = 0;

        for (int x : nums) {
            ans.push_back(x);
            chosenSum += x;

            if (chosenSum > totalSum - chosenSum) {
                break;
            }
        }

        return ans;
    }
};
