class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int maxEl = INT_MIN;
        int idx=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxEl) idx = i,maxEl = arr[i];
        }
        return idx;
    }
};