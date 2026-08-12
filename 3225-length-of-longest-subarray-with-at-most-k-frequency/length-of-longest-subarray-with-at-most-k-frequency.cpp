class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
     unordered_map<int, int> fre;

        int left = 0;
        int ans = 0;

        for(int right = 0; right < nums.size(); right++)
        {
            // Add current element
            fre[nums[right]]++;

            // If frequency becomes greater than k
            while(fre[nums[right]] > k)
            {
                fre[nums[left]]--;
                left++;
            }

            // Calculate current subarray length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};