
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        
        int m = queries.size();

        vector<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());
        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        vector<int> ans(m);
        vector<int> freq(n + 1, 0);

        int left = 0, right = 0;
        int active = 0;

        for (auto &query : q) {
            int t = query.first;
            int idx = query.second;
            while (right < logs.size() && logs[right][1] <= t) {
                int id = logs[right][0];
                freq[id]++;

                if (freq[id] == 1)
                    active++;

                right++;
            }


            while (left < right && logs[left][1] < t - x) {
                int id = logs[left][0];
                freq[id]--;

                if (freq[id] == 0)
                    active--;

                left++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};
