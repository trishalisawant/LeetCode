class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp;
    for (int i = 0; i < items1.size(); i++) {
        int value = items1[i][0];
        int weight = items1[i][1];
        mp[value] += weight;
    }
    for (int i = 0; i < items2.size(); i++) {
        int value = items2[i][0];
        int weight = items2[i][1];
        mp[value] += weight;
    }
    vector<vector<int>> ret;

    map<int, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
        vector<int> temp;
        temp.push_back(it->first);  
        temp.push_back(it->second);  
        ret.push_back(temp);
    }

    return ret; 
    }
};
