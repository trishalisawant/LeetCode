class Solution {
public:
    int divisorSubstrings(int num, int k) {
        //int size = num.size();
        int count=0;
        string n = to_string(num);
        for(int i=0;i<=n.size()-k;i++)
        {
            string sub = n.substr(i,k);
            int x = stoi(sub);
            if(x!=0 && num%x==0)
            {
                count++;
            }
        }
        return count;
    }
};