class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
    sort(prices.rbegin(),prices.rend());
    sort(discounts.rbegin(),discounts.rend());
    long double  total=0;
    for(int i:prices){ total+= i;}
    int n = min(prices.size(),discounts.size());
        for(int i=0;i<n;i++)
            {
                total-=(long double)prices[i]*discounts[i]/100.0;
            }
        return (double)total;
    }
};©leetcode
