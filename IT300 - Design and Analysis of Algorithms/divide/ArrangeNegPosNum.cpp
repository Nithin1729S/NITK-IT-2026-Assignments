#include <vector>
#include <algorithm>  // for std::swap

class Solution {
public:
    void arrangeNegPos(std::vector<int>& nums) {
        int pivot = 0;  // pivot is 0
        int j = 0;  // pointer to place negatives

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                std::swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
