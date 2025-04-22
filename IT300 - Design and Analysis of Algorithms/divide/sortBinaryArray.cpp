#include <vector>
#include <algorithm>  // for std::swap

class Solution {
public:
    void sortBinaryArray(std::vector<int>& nums) {
        int pivot = 1;  // pivot is 1
        int j = 0;  // pointer to place 0s

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                std::swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
