#include <vector>
using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while(start <= end) {
            int mid = (start + end) / 2;

            if(nums[mid] == target) return mid;

            if(nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return start;
        
        // return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};