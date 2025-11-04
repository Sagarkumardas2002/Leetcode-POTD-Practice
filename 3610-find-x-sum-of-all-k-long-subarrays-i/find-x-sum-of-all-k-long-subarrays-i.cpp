#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> answer;

        for (int i = 0; i <= n - k; i++) {
            map<int, int> mp;

            // Store frequency of elements in the current subarray
            for (int j = i; j < i + k; j++) {
                mp[nums[j]]++;
            }

            // Handle case: fewer distinct elements than x
            if ((int)mp.size() < x) {
                int total = accumulate(nums.begin() + i, nums.begin() + i + k, 0);
                answer.push_back(total);
                continue;
            }

            // Store {frequency, value} pairs
            vector<pair<int, int>> temp;
            for (auto it : mp) {
                temp.push_back({it.second, it.first});
            }

            // Sort by frequency desc, then value desc
            sort(temp.begin(), temp.end(), [](auto& a, auto& b) {
                if (a.first == b.first)
                    return a.second > b.second;
                return a.first > b.first;
            });

            // Compute x-sum
            int sum = 0, count = 0;
            for (auto& p : temp) {
                if (count == x) break;
                sum += p.first * p.second;
                count++;
            }

            answer.push_back(sum);
        }

        return answer;
    }
};
