class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin(),s.end());
        string left ="";
        string right ="";
        string middle ="";
        int i=0;
        while(i<s.size())
        {
            char ch = s[i];
            int count=0;
            while(i<s.size() && s[i]==ch)
            {
                count++;
                i++;
            }
            left += string(count/2,ch);
            if(count%2==1)
            {
                middle+=ch;
            }
        }
        right = left;
        reverse(right.begin(),right.end());
        return left+middle+right;
    }
};
