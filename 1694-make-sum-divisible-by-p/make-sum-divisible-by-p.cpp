class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;
        for (int x : nums) totalSum += x;

        int need = totalSum % p;
        if (need == 0) return 0;  // nothing to remove

        unordered_map<int, int> lastIndex;
        lastIndex[0] = -1; // prefix sum before starting

        long long prefix = 0;
        int answer = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % p;

            int target = (prefix - need + p) % p;

            if (lastIndex.count(target)) {
                answer = min(answer, i - lastIndex[target]);
            }

            lastIndex[prefix] = i;
        }

        return answer == nums.size() ? -1 : answer;
    }
};
