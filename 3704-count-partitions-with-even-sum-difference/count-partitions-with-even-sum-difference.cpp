class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int x : nums) totalSum += x;

        // If total sum is odd, no partition gives even difference
        if (totalSum % 2 == 1) return 0;

        // Otherwise all n-1 partitions are valid
        return n - 1;
    }
};
