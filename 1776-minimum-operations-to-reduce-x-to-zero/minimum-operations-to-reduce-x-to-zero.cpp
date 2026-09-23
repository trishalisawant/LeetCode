class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int total = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
        }

        int target = total - x;

        if(target < 0)
            return -1;

        int n = nums.size();
        int left = 0;
        int sum = 0;
        int maxLen = 0;

        for(int right = 0; right < n; right++)
        {
            sum += nums[right];

            while(sum > target)
            {
                sum -= nums[left];
                left++;
            }

            if(sum == target)
            {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        if(maxLen == 0)
        {
            if(target == 0)
                return n;
            else
                return -1;
        }

        return n - maxLen;
    }
};