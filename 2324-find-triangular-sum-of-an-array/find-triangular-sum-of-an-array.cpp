class Solution {
public:
    int triangularSum(vector<int>& nums) {
        // Repeat until only one element remains
        while (nums.size() > 1) {
            vector<int> newNums;
            for (int i = 0; i < nums.size() - 1; i++) {
                // (sum of adjacent elements) % 10
                newNums.push_back((nums[i] + nums[i + 1]) % 10);
            }
            nums = newNums; // replace old array
        }
        return nums[0]; // final single element
    }
};