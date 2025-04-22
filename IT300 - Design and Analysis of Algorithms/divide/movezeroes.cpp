#include <vector>
#include <algorithm>  // for std::swap

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                std::swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
