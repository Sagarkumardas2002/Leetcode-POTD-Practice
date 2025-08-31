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

            // take the maximum area found so far
            maxWater = max(maxWater, water);

            // move the pointer pointing to the shorter line
            if (nums[left] < nums[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};