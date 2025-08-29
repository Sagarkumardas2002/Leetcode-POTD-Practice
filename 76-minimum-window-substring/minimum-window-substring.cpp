class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
            return "";

        unordered_map<char, int> target, window;
        for (char c : t)
            target[c]++;

        int required = target.size(); // unique chars needed
        int formed = 0;               // unique chars matched so far
        int l = 0, r = 0;             // sliding window bounds
        int minLen = INT_MAX, startIndex = 0;

        while (r < s.size()) {
            char c = s[r];
            window[c]++;

            if (target.count(c) && window[c] == target[c]) {
                formed++;
            }

            // Try to shrink from the left
            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIndex = l;
                }

                char leftChar = s[l];
                window[leftChar]--;
                if (target.count(leftChar) &&
                    window[leftChar] < target[leftChar]) {
                    formed--;
                }
                l++;
            }

            r++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(startIndex, minLen);
    }
};