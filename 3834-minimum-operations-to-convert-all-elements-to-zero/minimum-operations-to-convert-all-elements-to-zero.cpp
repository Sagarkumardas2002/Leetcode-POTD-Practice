class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int operation = 0;
        stack<int> stk;

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && stk.top() > nums[i]) {
                stk.pop();
            }
            if (nums[i] == 0) {
                continue;
            }
            if (stk.empty() || stk.top() < nums[i]) {
                stk.push(nums[i]);
                operation++;
            }
        }
        return operation;
    }
};