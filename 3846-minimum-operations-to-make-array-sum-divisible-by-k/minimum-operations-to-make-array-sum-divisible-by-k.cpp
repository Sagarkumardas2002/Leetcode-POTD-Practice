class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = 0;
        for (int x : nums) sum += x;

        int r = sum % k;
        return r;   // need to subtract r to make sum divisible by k
    }
};