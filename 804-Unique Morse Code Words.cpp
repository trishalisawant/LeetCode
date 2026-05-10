class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",
            ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
            "...","-","..-","...-",".--","-..-","-.--","--.."
        };
        unordered_set<string> st;
        for(int i=0;i<words.size();i++)
        {
             string temp="";
            for(int j=0;j<words[i].size();j++)
            {
               char ch = words[i][j];
               temp+=morse[ch-'a'];
            }
          st.insert(temp);
        }
        return st.size();
    }
};
