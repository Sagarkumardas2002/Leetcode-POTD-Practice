class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;

        // Count existing 1s
        for (int num : nums)
            if (num == 1)
                ones++;

        if (ones > 0)
            return n - ones;  // each non-1 becomes 1 in one operation

        // Find smallest subarray with gcd = 1
        int minLen = INT_MAX;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = __gcd(g, nums[j]);
                if (g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break; // no need to extend further
                }
            }
        }

        // If no subarray with gcd=1 exists, impossible
        if (minLen == INT_MAX) return -1;

        // (minLen - 1) to make one 1, + (n - 1) to spread it
        return (minLen - 1) + (n - 1);
    }
};