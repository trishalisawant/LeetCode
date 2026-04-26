class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;
        bool insidePair = false;

        for (char ch : s) {
            if (ch == '|') {
                insidePair = !insidePair;
            } 
            else if (ch == '*' && !insidePair) {
                count++;
            }
        }

        return count;
    }
};
