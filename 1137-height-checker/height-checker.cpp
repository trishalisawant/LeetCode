class Solution {
public:
    int heightChecker(vector<int>& heights) {
      vector<int>original = heights;
        int size = heights.size();
        int count=0;
        sort(heights.begin(),heights.end());
        for(int i=0;i<size;i++)
        {
            if(original[i]!=heights[i])
            {
                count++;
                //i++;
            }
        }
        return count;  
    }
};