class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int>num =nums;
        reverse(nums.begin(),nums.end());
        num.insert(num.end(), nums.begin(), nums.end());

        return num;
    }
};
