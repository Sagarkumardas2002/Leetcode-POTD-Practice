class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = nums[i];
        }
        set<pair<long long, int>> min_pair;

        vector<int> next(n);
        vector<int> prev(n);
        for (int i = 0; i < n; i++) {
            next[i] = i + 1;
            prev[i] = i - 1;
        }
        int ans = 0;
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                count++;
            }
            min_pair.insert({a[i] + a[i + 1], i});
        }
        while (count > 0) {
            int currIdx = min_pair.begin()->second;
            int nextIdx = next[currIdx];
            int prevIdx = prev[currIdx];
            int next_nextIdx = next[nextIdx];

            if (a[currIdx] > a[nextIdx]) {
                count--;
            }
            if (prevIdx >= 0) {
                if (a[prevIdx] > a[currIdx] &&
                    a[prevIdx] <= a[currIdx] + a[nextIdx]) {
                    count--;
                } else if (a[prevIdx] <= a[currIdx] &&
                           a[prevIdx] > a[currIdx] + a[nextIdx]) {
                    count++;
                }
            }
            if (next_nextIdx < n) {
                if (a[next_nextIdx] >= a[nextIdx] &&
                    a[next_nextIdx] < a[currIdx] + a[nextIdx]) {
                    count++;
                } else if (a[next_nextIdx] < a[nextIdx] &&
                           a[next_nextIdx] >= a[currIdx] + a[nextIdx]) {
                    count--;
                }
            }
            min_pair.erase(min_pair.begin());
            if (prevIdx >= 0) {
                min_pair.erase({a[prevIdx] + a[currIdx], prevIdx});
                min_pair.insert(
                    {a[prevIdx] + a[currIdx] + a[nextIdx], prevIdx});
            }
            if (next_nextIdx < n) {
                min_pair.erase({a[nextIdx] + a[next_nextIdx], nextIdx});
                min_pair.insert(
                    {a[next_nextIdx] + a[nextIdx] + a[currIdx], currIdx});
                prev[next_nextIdx] = currIdx;
            }
            next[currIdx] = next_nextIdx;
            a[currIdx] = a[currIdx] + a[nextIdx];
            ans++;
        }
        return ans;
    }
};