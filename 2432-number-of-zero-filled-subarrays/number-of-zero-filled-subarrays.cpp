class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();
        long long len = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                len++; // extend current zero block
            } else {
                result += (len * (len + 1)) / 2; // apply formula
                len = 0;                         // reset for next block
            }
        }
        // Add last block if array ends with zeros
        result += (len * (len + 1)) / 2;

        return result;
    }
};