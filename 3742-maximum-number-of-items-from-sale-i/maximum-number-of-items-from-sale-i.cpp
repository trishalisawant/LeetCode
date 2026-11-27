
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();
        int maxFactor = 1500;

        // Count items having each factor
        vector<int> cnt(maxFactor + 1, 0);

        for (auto& item : items) {
            cnt[item[0]]++;
        }

        // Count how many factors are multiples of each factor
        vector<int> ways(maxFactor + 1, 0);

        for (int i = 1; i <= maxFactor; i++) {
            for (int j = i; j <= maxFactor; j += i) {
                ways[i] += cnt[j];
            }
        }

        // Group items according to their price
        vector<vector<pair<int, int>>> groups(1501);

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            if (price <= budget) {
                groups[price].push_back({ways[factor], price});
            }
        }

        const int NEG = -1000000000;

        // DP for items having higher prices
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        int ans = 0;

        // Process prices from high to low
        for (int p = 1500; p >= 1; p--) {

            vector<int> with(budget + 1, NEG);

            // Select at least one item with price p
            for (auto [w, price] : groups[p]) {

                for (int c = budget; c >= price; c--) {

                    if (dp[c - price] != NEG) {
                        with[c] = max(with[c],
                                      dp[c - price] + w);
                    }

                    if (with[c - price] != NEG) {
                        with[c] = max(with[c],
                                      with[c - price] + w);
                    }
                }
            }

            // Calculate the maximum answer
            int best = NEG;

            for (int c = 0; c <= budget; c++) {
                if (with[c] != NEG) {
                    best = max(best, p * with[c] - c);
                }
            }

            if (best != NEG) {
                ans = max(ans, (budget + best) / p);
            }

            // Add current price items to normal DP
            for (auto [w, price] : groups[p]) {

                for (int c = budget; c >= price; c--) {
                    if (dp[c - price] != NEG) {
                        dp[c] = max(dp[c],
                                    dp[c - price] + w);
                    }
                }
            }
        }

        return ans;
    }
};
