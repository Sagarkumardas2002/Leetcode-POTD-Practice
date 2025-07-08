class Solution {
public:
    vector<vector<int>> dp;

    // Binary search to find the next index where start > events[i][1]
    int findNextIndex(vector<vector<int>>& events, int currEnd) {
        int lo = 0, hi = events.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (events[mid][0] > currEnd)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }

    int find(int i, int k, vector<vector<int>>& events) {
        if (k == 0 || i >= events.size())
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];

        // Skip current
        int res = find(i + 1, k, events);

        // Take current
        int next = findNextIndex(events, events[i][1]);
        res = max(res, events[i][2] + find(next, k - 1, events));

        return dp[i][k] = res;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());  // Sort by start time
        dp.resize(n, vector<int>(k + 1, -1));
        return find(0, k, events);
    }
};