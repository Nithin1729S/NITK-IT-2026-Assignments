#include <iostream>
#include <vector>
using namespace std;

int sumDivideAndConquer(const vector<int>& nums, int lo, int hi) {
    if (lo == hi) {
        return nums[lo]; 
    }

    int mid = lo + (hi - lo) / 2;
    int leftSum = sumDivideAndConquer(nums, lo, mid);     
    int rightSum = sumDivideAndConquer(nums, mid + 1, hi); 

    return leftSum + rightSum; 
}


double averageDivideAndConquer(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0.0; 
    }
    int totalSum = sumDivideAndConquer(nums, 0, n - 1); 
    return static_cast<double>(totalSum) / n; 
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Average: " << averageDivideAndConquer(nums) << endl;
    return 0;
}
