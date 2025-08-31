class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int maxWater = 0;
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int width = right - left;
            int height = min(nums[left], nums[right]);
            int water = width * height;
            maxWater = max(maxWater, water);

            if (nums[left] > nums[right]) {
                right--;
            } else {
                left++;
            }
        }
        return maxWater;
    }
};