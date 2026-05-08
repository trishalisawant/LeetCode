class Solution {
public:

    bool isPrime(int n)
    {
        if(n < 2) return false;

        for(int i = 2; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        // Store indices divisible by each prime factor
        for(int i = 0; i < n; i++)
        {
            int x = nums[i];

            for(int p = 2; p * p <= x; p++)
            {
                if(x % p == 0)
                {
                    mp[p].push_back(i);

                    while(x % p == 0)
                    {
                        x /= p;
                    }
                }
            }

            if(x > 1)
            {
                mp[x].push_back(i);
            }
        }

        queue<pair<int,int>> q;
        vector<int> vis(n, 0);

        q.push({0, 0});
        vis[0] = 1;

        unordered_set<int> usedPrime;

        while(!q.empty())
        {
            auto [idx, steps] = q.front();
            q.pop();

            if(idx == n - 1)
            {
                return steps;
            }

            // Move right
            if(idx + 1 < n && !vis[idx + 1])
            {
                vis[idx + 1] = 1;
                q.push({idx + 1, steps + 1});
            }

            // Move left
            if(idx - 1 >= 0 && !vis[idx - 1])
            {
                vis[idx - 1] = 1;
                q.push({idx - 1, steps + 1});
            }

            // Prime teleportation
            int val = nums[idx];

            if(isPrime(val) && !usedPrime.count(val))
            {
                for(int nextIdx : mp[val])
                {
                    if(!vis[nextIdx])
                    {
                        vis[nextIdx] = 1;
                        q.push({nextIdx, steps + 1});
                    }
                }

                usedPrime.insert(val);
            }
        }

        return -1;
    }
};
