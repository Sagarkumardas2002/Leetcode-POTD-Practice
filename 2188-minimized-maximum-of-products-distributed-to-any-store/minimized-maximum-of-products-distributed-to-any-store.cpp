class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());
        int ans = right;

        auto canDistribute = [&](int maxLoad) {
            long long storesNeeded = 0;
            for (int q : quantities) {
                storesNeeded += (q + maxLoad - 1) / maxLoad; 
                if (storesNeeded > n) return false;
            }
            return true;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(mid)) {
                ans = mid;
                right = mid - 1; // try smaller
            } else {
                left = mid + 1;  // need bigger
            }
        }
        return ans;
    }
};
