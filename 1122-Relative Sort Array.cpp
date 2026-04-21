class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> freq;
        for (int num : arr1) {
            freq[num]++;
        }

        vector<int> result;
        for (int num : arr2) {
            while (freq[num] > 0) {
                result.push_back(num);
                freq[num]--;
            }
        }

        for (auto it : freq) {
            while (it.second > 0) {
                result.push_back(it.first);
                it.second--;
            }
        }

        return result;
    }
};
