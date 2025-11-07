class Solution {
public:
    bool canAchieve(long long minPower, vector<long long>& power, int r, long long k) {
        int n = power.size();
        vector<long long> added(n, 0);
        long long used = 0, windowAdd = 0;
        
        for (int i = 0; i < n; i++) {
            if (i - r - 1 >= 0)
                windowAdd -= added[i - r - 1];
            
            long long currPower = power[i] + windowAdd;
            
            if (currPower < minPower) {
                long long need = minPower - currPower;
                if (need > k - used) return false;  // not enough stations
                
                used += need;
                int pos = min(n - 1, i + r);
                added[pos] += need;
                windowAdd += need;
            }
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> power(n, 0);
        vector<long long> prefix(n + 1, 0);
        
        // Step 1: Calculate power of each city
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stations[i];
        
        for (int i = 0; i < n; i++) {
            int left = max(0, i - r);
            int right = min(n - 1, i + r);
            power[i] = prefix[right + 1] - prefix[left];
        }

        // Step 2: Binary search for maximum possible minimum power
        long long low = 0, high = 1e18, ans = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (canAchieve(mid, power, r, k)) {
                ans = mid;
                low = mid + 1;  // try for higher minimum
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
