class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban;
        
        for(int i = 0; i < banned.size(); i++) {
            ban.insert(banned[i]);
        }

        unordered_map<string, int> freq;
        string word = "";

        for(int i = 0; i <= paragraph.size(); i++) {
            
            if(i < paragraph.size() && isalpha(paragraph[i])) {
                word += tolower(paragraph[i]);
            }
            else {
                if(word != "") {
                    if(ban.find(word) == ban.end()) {
                        freq[word]++;
                    }
                    word = "";
                }
            }
        }

        string answer = "";
        int maxCount = 0;

        for(auto it : freq) {
            if(it.second > maxCount) {
                maxCount = it.second;
                answer = it.first;
            }
        }

        return answer;
    }
};