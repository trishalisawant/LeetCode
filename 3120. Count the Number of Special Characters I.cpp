class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char>lower;
        unordered_set<char>upper;
        for(char ch : word)
        {
            if(islower(ch))
            {
                lower.insert(ch);
            }
            else if(isupper(ch))
            {
                upper.insert(tolower(ch));
            }
        }
        int ans=0;
        for(char ch : lower)
        {
            if(upper.count(ch))
            {
                ans++;
            }
        }
        return ans;
    }
};
