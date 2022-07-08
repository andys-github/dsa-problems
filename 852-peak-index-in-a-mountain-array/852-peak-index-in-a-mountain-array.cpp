class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;
        
        while(start <= end) {
            int mid = (start + end) / 2;
            
            int prev = arr[mid - 1];
            int curr = arr[mid];
            int next = arr[mid + 1];
            
            if(curr > prev && curr > next)
                return mid;
            
            if(curr > prev && curr < next) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        
        return -1;
    }
};