class Solution {
public:
    bool checkIfPangram(string sentence) {
        string abs = "abcdefghijklmnopqrstuvwxyz";
        for(char c:abs)
        {
            if(sentence.find(c)==-1)
            {
                return false;
            }
        }
        return true;
    }
};