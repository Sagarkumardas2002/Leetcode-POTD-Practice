class Solution {
public:
    // helper function to check if number contains digit '0'
    bool hasZero(int x) {
        while (x > 0) {
            if (x % 10 == 0) return true;
            x /= 10;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (!hasZero(a) && !hasZero(b)) {
                return {a, b};  // directly return as soon as found
            }
        }
        return {}; // should never reach here for valid input
    }
};
