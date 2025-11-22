class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int num : nums) {
            int a = num % 3;
            int b = 3 - a;
            count += min(a, b);
        }
        return count;
    }
};