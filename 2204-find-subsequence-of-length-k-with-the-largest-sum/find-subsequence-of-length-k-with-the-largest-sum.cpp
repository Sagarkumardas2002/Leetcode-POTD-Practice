class Solution {
public:
    static bool lambda(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    }

    static bool compareIndex(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n)
            return nums;

        vector<pair<int, int>> element;
        for (int i = 0; i < n; i++) {
            element.push_back({nums[i], i});
        }

        // Sort by value descending
        sort(element.begin(), element.end(), lambda);

        // Keep top k elements
        element.resize(k);

        // Sort by original index to maintain order
        sort(element.begin(), element.end(), compareIndex);

        vector<int> answer;
        for (int i = 0; i < k; i++) {
            answer.push_back(element[i].first);
        }

        return answer;
    }
};
