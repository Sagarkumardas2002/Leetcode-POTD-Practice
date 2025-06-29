class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;  // To avoid overflow, we take modulo of final answers

        // Step 1: Sort the input array so we can use two pointers logic
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Step 2: Precompute powers of 2 modulo MOD
        // pow2[i] = 2^i % MOD
        vector<int> pow2(n);
        pow2[0] = 1;
        for (int i = 1; i < n; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        // Step 3: Use two pointers approach to count valid subsequences
        int left = 0;
        int right = n - 1;
        int totalValidSubsequences = 0;

        while (left <= right) {
            int minElement = nums[left];
            int maxElement = nums[right];

            // Check if the sum of min and max elements is within the target
            if (minElement + maxElement <= target) {
                // All subsequences formed using elements between left and right (inclusive)
                // where min is nums[left] and max is nums[right] will be valid
                // Total = 2^(right - left) possible subsequences
                int numOfSubseq = pow2[right - left];
                totalValidSubsequences = (totalValidSubsequences + numOfSubseq) % MOD;

                ++left;
            } else {
                --right;
            }
        }

        return totalValidSubsequences;
    }
};
