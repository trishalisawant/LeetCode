class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>st;
        unordered_set<int>ans;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                    st.insert(nums[i]^nums[j]);
                
            }
        }
        for(int num:st)
        {
            for(int s:nums){
                ans.insert(num^s);
            }
        }
        return ans.size();
    }
};
