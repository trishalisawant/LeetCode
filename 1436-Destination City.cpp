class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> startCities;
    for (int i = 0; i < paths.size(); i++) {
        startCities.insert(paths[i][0]);
    }
    for (int i = 0; i < paths.size(); i++) {
        if (startCities.find(paths[i][1]) == startCities.end()) {
            return paths[i][1];
        }
    }
    return "";
    }
};
