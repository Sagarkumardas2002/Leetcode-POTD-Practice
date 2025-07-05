class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int it : arr) {
            mp[it]++;
        }

        int largestLucky = -1;
        for (auto it : mp) {
            if (it.first == it.second) {
                largestLucky = max(largestLucky, it.first);
            }
        }
        return largestLucky;
    }
};