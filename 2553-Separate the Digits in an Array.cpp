class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            int num = nums[i]; vector<int>temp;
            int rev=0;
            while(num>0)
            {
                int digit = num%10;
                temp.push_back(digit);
                num/=10;
            }
            reverse(temp.begin(),temp.end());
            for(int i=0;i<temp.size();i++)
            {
                int d = temp[i];
                ans.push_back(d);
            }
        }
        return ans;
    }
};
