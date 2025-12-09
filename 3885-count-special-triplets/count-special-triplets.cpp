class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        long long ans = 0;
        int n = nums.size();

        unordered_map<int, long long> leftFreq;
        unordered_map<int, long long> rightFreq;

        // Fill right side frequency map
        for (int x : nums) rightFreq[x]++;

        for (int j = 0; j < n; j++) {
            int mid = nums[j];
            rightFreq[mid]--; // We are now at j, so remove from right

            long long target = mid * 2LL;

            long long leftCount = leftFreq[target];
            long long rightCount = rightFreq[target];

            ans = (ans + (leftCount * rightCount) % MOD) % MOD;

            leftFreq[mid]++; // Add current to left side
        }

        return ans;
    }
};
