class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
         int size = nums.size();
        vector<int>left(size);
        vector<int>right(size);
        vector<int>result(size);
        left[0]=0;
        for(int i=1;i<size;i++)
        {
           left[i]=left[i-1]+nums[i-1];

        }
        right[size-1]=0;
        for(int i=size-2;i>=0;i--)
        {
            right[i]=right[i+1]+nums[i+1];
        }
        for(int i=0;i<size;i++)
        {
         result[i]=abs(left[i]-right[i]);
        }
        return result;
    }
};
