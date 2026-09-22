class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;

        int i = 0;

        while(i < nums.size())
        {
            if(s.find(nums[i]) != s.end())
            {
                return true;
            }

            s.insert(nums[i]);

            if(s.size() > k)
            {
                s.erase(nums[i - k]);
            }

            i++;
        }

        return false;
    }
};