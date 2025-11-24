class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> answer;
        answer.reserve(nums.size());

        int remainder = 0;  // we store only remainder mod 5

        for (int bit : nums) {
            // Update remainder when appending this bit
            remainder = (remainder * 2 + bit) % 5;

            // If remainder is 0, number is divisible by 5
            answer.push_back(remainder == 0);
        }

        return answer;
    }
};
