
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        int maxFactor = 0;
        long long minPrice = LLONG_MAX;
        for (auto &item : items) {
            maxFactor = max(maxFactor, item[0]);
            minPrice = min(minPrice, (long long)item[1]);
        }
        vector<int> freq(maxFactor + 1, 0);

        for (auto &item : items) {
            freq[item[0]]++;
        }
        vector<int> gain(maxFactor + 1, 0);

        for (int i = 1; i <= maxFactor; i++) {
            for (int j = i; j <= maxFactor; j += i) {
                gain[i] += freq[j];
            }
            gain[i]--; 
        }
        vector<pair<int, int>> bonus;

        for (auto &item : items) {
            int factor = item[0];
            int price = item[1];

            if (gain[factor] > 0 && price < 2 * minPrice) {
                bonus.push_back({price, gain[factor]});
            }
        }
        sort(bonus.begin(), bonus.end());

        long long ans = 0;
        long long remaining = budget;
        for (auto &p : bonus) {
            long long price = p.first;
            long long count = p.second;

            long long take = min(count, remaining / price);

            ans += take * 2;
            remaining -= take * price;
        }
        ans += remaining / minPrice;

        return (int)ans;
    }
};
