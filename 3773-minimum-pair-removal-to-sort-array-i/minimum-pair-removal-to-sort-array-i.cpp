class Solution {
public:
    bool isNonDecreasing(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;
        while (!isNonDecreasing(nums) && nums.size() > 1) {
            int mini = INT_MAX;
            int idx = -1;
            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < mini) {
                    mini = sum;
                    idx = i;
                }
            }
            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);
            operations++;
        }
        return operations;
    }
};