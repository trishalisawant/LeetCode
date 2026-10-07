class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Count frequency of each number
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        // bucket[i] stores numbers that appear i times
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto x : freq) {
            bucket[x.second].push_back(x.first);
        }

        vector<int> ans;

        // Start from highest frequency
        for (int i = nums.size(); i >= 1; i--) {

            for (int j = 0; j < bucket[i].size(); j++) {
                ans.push_back(bucket[i][j]);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};