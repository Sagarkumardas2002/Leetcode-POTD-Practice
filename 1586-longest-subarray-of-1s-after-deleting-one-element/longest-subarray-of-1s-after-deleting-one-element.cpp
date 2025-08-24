class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, zeros = 0, ans = 0;
        int n = nums.size();

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) zeros++;

            // shrink window if more than 1 zero
            while (zeros > 1) {
                if (nums[left] == 0) zeros--;
                left++;
            }

            // length after deleting 1 element
            ans = max(ans, right - left + 1 - 1);
        }
        return ans;
    }
};
