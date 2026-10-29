class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       int maxIndex = 0;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

     return  maxIndex;

    }
};