class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>f(n*n+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                f[grid[i][j]]++;
            }
        }
            int missing,duplicate;
            for(int i=1;i<=n*n;i++)
            {
                 if(f[i]==2)
                 {
                    duplicate=i;
                 }
                else if(f[i]==0)
                {
                    missing=i;
                }
            }
        return {duplicate,missing};
    }
};
