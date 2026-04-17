class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
         unordered_set<int> common(nums[0].begin(), nums[0].end());

        for (int i = 1; i < nums.size(); i++) {
            unordered_set<int> temp(nums[i].begin(), nums[i].end());
            unordered_set<int> newCommon;

            for (int x : common) {
                if (temp.count(x)) {
                    newCommon.insert(x);
                }
            }

            common = newCommon;
        }

        vector<int> result(common.begin(), common.end());
        sort(result.begin(), result.end());

        return result;
    }
};
