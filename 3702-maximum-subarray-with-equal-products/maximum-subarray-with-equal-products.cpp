
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            long long product = 1;
            int g = 0, l = 1;

            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);

                // Avoid multiplication overflow
                if (product > 1000000000000000000LL / nums[j])
                    break;

                product *= nums[j];

                if (product == 1LL * l * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
