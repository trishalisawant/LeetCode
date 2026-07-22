class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater =0;
        int n =height.size();
        int l=0,r=n-1;
        while(l<r){
                int width = r-l;
                int he = min(height[l],height[r]);
                int currwater = width * he;
                maxwater = max(maxwater,currwater);
                height[l]<height[r]?l++:r--;
            }
         return  maxwater;
    }
};
