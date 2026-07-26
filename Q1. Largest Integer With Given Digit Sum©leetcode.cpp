class Solution {
public:
    int largestInteger(int n, int s) {
        if( s > 9*n) return -1;

       string ans = "";

        for(int i=0;i<n;i++) {
            if(s>=9) {
               ans+='9';
                s-=9;
            } else {
                ans+=char('0'+s);
              s=0;
            }
        }

     return stoll(ans);
    }
};©leetcode
