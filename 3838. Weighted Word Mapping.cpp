class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res="";
        for(string s : words)
        {
            int sum =0;
            for(int i=0;i<s.size();i++)
            {
              sum += weights[s[i]-'a'];
            }

         int mod = sum % 26;
        int reverse = 25 - mod;
        res += char(reverse +'a');
        }
        return res;
    }
};
